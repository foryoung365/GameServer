////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/05
// Describe:≤‚ ‘
////////////////////////////////////////////////////////////////////////
#include "juce_core/juce_core.h"
#include "BaseDefine.h"
#include "zmq.h"

int main(void)
{

	juce::Time tCurr = juce::Time::getCurrentTime();
	printf("%s\n", tCurr.toString(true, true, true, true));

	juce::IPAddress objIPAddr("192.168.1.1");
	printf("%s %u\n", objIPAddr.toString(), ntohl(*((unsigned int*)(objIPAddr.address))));

	void* context = zmq_ctx_new();
	if (context == NULL)
	{
		return -1;
	}

	void* socket = zmq_socket(context, ZMQ_REQ);
	zmq_bind(socket, "tcp://127.0.0.1:35400");

	int nCount = 0;
	while (1)
	{
		zmq_msg_t request;
		zmq_msg_init(&request);
		zmq_msg_recv(&request, socket, 0);
		printf("Received Hello %d from Client...\n", nCount);
		zmq_msg_close(&request);

		zmq_msg_t reply;
		zmq_msg_init_size(&reply, 5);
		memcpy(zmq_msg_data(&reply), "World", 5);
		zmq_msg_send(&reply, socket, 0);
		printf("Sending World %d\n", nCount);
		zmq_msg_close(&reply);
		++nCount;
		Sleep(500);
	}
	
	zmq_close(socket);
	zmq_ctx_destroy(context);

	getchar();

	return 0;
}