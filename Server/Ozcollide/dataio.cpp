/*
OZCollide - Collision Detection Library
Copyright (C) 2014 Igor Kravtchenko

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Contact the author: igor@tsarevitch.org
*/

#include <ozcollide/ozcollide.h>

#ifndef OZCOLLIDE_PCH
#include <ozcollide/dataio.h>
#endif

#ifdef WIN32
#include <winsock.h>
#else
#include <netinet/in.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

// convert from a "standard" float32 (IEEE754 formated) to local FPU internal format and vice-versa
static int double2buffer(double x, unsigned char *p, int littleEndian);
static double buffer2double(const unsigned char *p, int littleEndian);

// DATA IN

DataIn::DataIn()
{
	fileHandle_ = NULL;
	mem_ = NULL;
	memSize_ = 0;
	byteOff_ = 0;
};

DataIn::~DataIn()
{
};

bool DataIn::open(const char *_fileName)
{
	input_ = SOURCE_DISK;
	char *old = fileName_;
	fileName_ = _strdup(_fileName);
	SAFE_FREE(old);

	fileHandle_ = fopen(fileName_, "rb");
	if (fileHandle_ == NULL)
		return false;

	byteOff_ = 0;
	return true;
}

void DataIn::open(void *_mem, int _size)
{
	input_ = SOURCE_MEMORY;
	mem_ = (char*) _mem;
	memSize_ = _size;
}

DataIn::SOURCE_TYPE DataIn::getSourceType() const
{
	return input_;
}

bool DataIn::close()
{
	if (input_ == SOURCE_DISK) {
		if (fileHandle_ && fclose(fileHandle_) != 0)
			return false;
	}
	fileHandle_ = NULL;

	return true;
}

bool DataIn::isOpen() const
{
	if (input_ == SOURCE_DISK)
		return fileHandle_ ? true : false;
	else
		return true;
}

bool DataIn::eof() const
{
	if (input_ == SOURCE_DISK)
		return feof(fileHandle_) == 0 ? false : true;

	return byteOff_ >= getSize() ? true : false;
}

bool DataIn::error() const 
{
	if (input_ == SOURCE_DISK)
		return ferror(fileHandle_) == 0 ? false : true;
	return false;
}

const char* DataIn::getFileName() const
{
	return fileName_;
}

bool DataIn::advance(int _n)
{
	if (input_ == SOURCE_DISK)
		return fseek(fileHandle_, _n, SEEK_CUR);
	byteOff_ += _n;
	return true;
}

bool DataIn::seek(int _n)
{
	if (input_ == SOURCE_DISK) {
		if (fseek(fileHandle_, _n, SEEK_SET) == 0)
			return true;
	}
	else {
		if (byteOff_ < 0 || byteOff_ > memSize_)
			return false;
		else {
			byteOff_ = _n;
			return true;
		}
	}

	return false;
}

int DataIn::tell() const
{
	if (input_ == SOURCE_DISK)
		return ftell( fileHandle_ );
	return byteOff_;
}

int DataIn::getSize() const
{              
	int res;
	if (input_ == SOURCE_DISK) {
		int savePos, fileSize;
		savePos = ftell( fileHandle_ );
		res = fseek(fileHandle_, 0L, SEEK_END);
		fileSize = ftell( fileHandle_ );
		res = fseek(fileHandle_, savePos, SEEK_SET);
		return fileSize;
	}
	return memSize_;
}

int DataIn::read(void *_dest, int _nbBytes)
{
	if (input_ == SOURCE_DISK) {
		size_t nbRead;
		nbRead = fread(_dest, 1, _nbBytes, fileHandle_);
		return nbRead;
	}

	size_t toRead;
	if (byteOff_ + _nbBytes <= memSize_)
		toRead = _nbBytes;
	else
		toRead = memSize_ - byteOff_;

	if (toRead == 0)
		return 0;
	memcpy(_dest, (char*)mem_ + byteOff_, toRead);
	byteOff_ += toRead;
	return toRead;
}

int DataIn::readStrZ(char *_dest)
{
	char *buf = _dest;
	int nb = 0;
	while(!eof() && !ferror(fileHandle_)) {
		char c = readByte(); nb++;
		*buf++ = c;
		if (!c)
			break;
	}
	return nb;
}

char DataIn::readByte()
{
	char c = 0;
	int res = read(&c, 1); 
	return c;
}

short DataIn::readWord()
{
	short s = 0;
	int res = read(&s, 2);
	return ntohs(s);
}

int DataIn::readDword()
{
	int i = 0;
	int res = read(&i, 4);
	return ntohl(i);
}

float DataIn::readFloat()
{
	float f;
	int res = read(&f, 4);

	int a = *((int*)&f);
	int n = ntohl(a);
	*((int*)&f) = n;

#ifndef FPU_IEEE754
	f = (float) buffer2double((const unsigned char*)&f, 0);
#endif

	return f;
}

// DATA OUT

DataOut::DataOut()
{
	fileHandle_ = NULL;
};

DataOut::~DataOut()
{
};

bool DataOut::open(const char *_fileName)
{
	char *old = fileName_;
	fileName_ = _strdup(_fileName);
	SAFE_FREE(old);

	fileHandle_ = fopen(fileName_, "wb");
	if (fileHandle_ == NULL)
		return false;

	return true;
}

bool DataOut::close()
{
	if (fileHandle_ && fclose(fileHandle_) != 0)
		return false;
	fileHandle_ = NULL;
	return true;
}

bool DataOut::isOpen() const
{
	return fileHandle_ ? true : false;
}

bool DataOut::eof() const
{
	return feof(fileHandle_) == 0 ? false : true;
}

const char* DataOut::getFileName() const
{
	return fileName_;
}

bool DataOut::advance(int _n)
{
	int res = fseek(fileHandle_, _n, SEEK_CUR);
	if (res)
		return false;
	return true;
}

bool DataOut::seek(int _n)
{
	int res = fseek(fileHandle_, _n, SEEK_SET);
	if (res)
		return false;
	return true;
}

int DataOut::tell() const
{
	return ftell( fileHandle_ );
}

int DataOut::write(const void *_src, int _nbBytes)
{
	int res = fwrite(_src, 1, _nbBytes, fileHandle_);
	return res;
}

int DataOut::writeStr(const char *_str)
{
	return write((const void*)_str, strlen(_str));
}

int DataOut::writeStrZ(const char *_str)
{
	int res = 0;
	int nb = strlen(_str);
	if (nb)
		res = fwrite(_str, 1, nb, fileHandle_);
	res = fputc(0, fileHandle_);
	res++;
	return res;
}

int DataOut::writeByte(char _val)
{
	return write(&_val, 1);
}

int DataOut::writeWord(short _val)
{
	short n = htons(_val);
	return write(&n, 2);
}

int DataOut::writeDword(int _val)
{
	int n = htonl(_val);
	return write(&n, 4);
}

int DataOut::writeFloat(float _val)
{
#ifndef FPU_IEEE754
	unsigned char ieee[4];
	double2buffer(_val, ieee, 0);
	return write(ieee, 4);
#else
	int *ptr = (int*)&_val;
	int i = *ptr;
	int n = htonl(i);
	return write(&n, 4);
#endif
}

static int double2buffer(double _x, unsigned char *_p, int _littleEndian)
{
	unsigned char sign;
	int e;
	double f;
	unsigned int fbits;
	int incr = 1;

	if (_littleEndian) {
		_p += 3;
	    incr = -1;
	}

	if (_x < 0) {
		sign = 1;
	    _x = -_x;
	}
	else
		sign = 0;

	f = frexp(_x, &e);

	// Normalize f to be in the range [1.0, 2.0)
	if (0.5 <= f && f < 1.0) {
		f *= 2.0;
		e--;
	}
	else if (f == 0.0)
		e = 0;
	else {
		return -1;
	}

	if (e >= 128)
		goto overflow;
	else if (e < -126) {
		// Gradual underflow
		f = ldexp(f, 126 + e);
		e = 0;
	}
	else if (!(e == 0 && f == 0.0)) {
		e += 127;
		f -= 1.0; // Get rid of leading 1
	}

	f *= 8388608.0; // 2**23
	fbits = (unsigned int)(f + 0.5); // Round
	if (fbits >> 23) {
		// The carry propagated out of a string of 23 1 bits.
		fbits = 0;
		++e;
		if (e >= 255)
			goto overflow;
	}

	// First byte
	*_p = (sign << 7) | (e >> 1);
	_p += incr;

	// Second byte
	*_p = (char) (((e & 1) << 7) | (fbits >> 16));
	_p += incr;

	// Third byte
	*_p = (fbits >> 8) & 0xFF;
	_p += incr;

	// Fourth byte
	*_p = fbits & 0xFF;

	// Done 
	return 0;

overflow:
	return -1;
}

static double buffer2double(const unsigned char *p, int littleEndian)
{
	unsigned char sign;
	int e;
	unsigned int f;
	double x;
	int incr = 1;

	if (littleEndian) {
		p += 3;
		incr = -1;
	}

	// First byte
	sign = (*p >> 7) & 1;
	e = (*p & 0x7F) << 1;
	p += incr;

	// Second byte
	e |= (*p >> 7) & 1;
	f = (*p & 0x7F) << 16;
	p += incr;

	 // Third byte
	f |= *p << 8;
	p += incr;

	// Fourth byte
	f |= *p;

	x = (double)f / 8388608.0;

	// XXX This sadly ignores Inf/NaN issues
	if (e == 0)
		e = -126;
	else {
		x += 1.0;
		e -= 127;
	}
	x = ldexp(x, e);

	if (sign)
		x = -x;

	return x;
}

LEAVE_NAMESPACE
