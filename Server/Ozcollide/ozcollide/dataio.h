/*
OZCollide - Collision Detection Library
Copyright (C) 2006-2014 by Igor Kravtchenko

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

#ifndef OZCOLLIDE_DATAIO_H
#define OZCOLLIDE_DATAIO_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

/**
 * An input pin to read data.
 */
class DataIn {
public:
    
    /**
     * Defines the location of the input pin.
     */
    enum SOURCE_TYPE {
        SOURCE_DISK, /**< Data come from disk.*/
        SOURCE_MEMORY /**< Data come from memory.*/
    };

    OZCOLLIDE_API DataIn();
    OZCOLLIDE_API virtual ~DataIn();

    OZCOLLIDE_API bool open(const char *fileName);
    OZCOLLIDE_API void open(void *mem, int size);
 
    OZCOLLIDE_API SOURCE_TYPE getSourceType() const;

    OZCOLLIDE_API bool close();
    OZCOLLIDE_API bool isOpen() const;

    OZCOLLIDE_API bool eof() const;
    OZCOLLIDE_API bool error() const;

    OZCOLLIDE_API const char* getFileName() const;
    OZCOLLIDE_API bool advance(int n);
    OZCOLLIDE_API bool seek(int n);
    OZCOLLIDE_API int tell() const;
    OZCOLLIDE_API int getSize() const;

    OZCOLLIDE_API int read(void *dest, int nbBytes);
    OZCOLLIDE_API int readStrZ(char *dest);
    OZCOLLIDE_API char readByte();
    OZCOLLIDE_API short readWord();
    OZCOLLIDE_API int readDword();
    OZCOLLIDE_API float readFloat();

private:
    SOURCE_TYPE	input_;
    FILE *fileHandle_;
    char *mem_;
    int memSize_;
    int byteOff_;
    char *fileName_;
};
 
/**
 * An output pin to write data.
 */
class DataOut {
public:

    OZCOLLIDE_API DataOut();
    OZCOLLIDE_API virtual ~DataOut();

    OZCOLLIDE_API bool open(const char *fileName);
    OZCOLLIDE_API bool close();

    OZCOLLIDE_API bool isOpen() const;
    OZCOLLIDE_API bool eof() const;

    OZCOLLIDE_API const char* getFileName() const;
    OZCOLLIDE_API bool advance(int n);
    OZCOLLIDE_API bool seek(int n);
    OZCOLLIDE_API int tell() const;
 
    OZCOLLIDE_API int write(const void *src, int nbBytes);
    OZCOLLIDE_API int writeStr(const char *);
    OZCOLLIDE_API int writeStrZ(const char *);
 
    OZCOLLIDE_API int writeByte(char);
    OZCOLLIDE_API int writeWord(short);
    OZCOLLIDE_API int writeDword(int);
    OZCOLLIDE_API int writeFloat(float);
 
private:
    FILE *fileHandle_;
    int memSize_;
    char *fileName_;
};

LEAVE_NAMESPACE

#endif
