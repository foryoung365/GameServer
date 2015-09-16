////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:游服相关定义
////////////////////////////////////////////////////////////////////////
#ifndef _GAMESERVERDEF_H_
#define _GAMESERVERDEF_H_

#define GAME_SERVER_VERSION					1000

#define CONFIG_FILE_NAME						"GameServer.ini"
#define GAME_SERVER_SECTION					"GameServer"
#define GAME_SERVER_ID						"SERVER_ID"
#define GAME_SERVER_SOCKET_SECTION			"GameServerSocket"
#define GAME_SERVER_SOCKET_PORT				"GAME_PORT"
#define GAME_SERVER_SOCKET_MAXCLIENT		"MAX_CLIENT"
#define ACCOUNT_SERVER_SECTION				"AccountServer"
#define ACCOUNT_SERVER_IP					"ACCOUNT_IP"
#define ACCOUNT_SERVER_PORT					"ACCOUNT_PORT"
#define DATABASE_SECTRION					"Database"
#define DATABASE_IP							"DB_IP"
#define DATABASE_USER							"DB_USER"
#define DATABASE_PASSWORD					"DB_PW"
#define DATABASE_DATABASE					"DB_DB"

#define GAME_SERVER_SYSLOG_DIR			"syslog"
#define GAME_SERVER_GMLOG_DIR			"gmlog"

#define GAME_SERVER_LOG_FILENAME			"GameServer_"
#define GAME_SERVER_LOG_SUFFIX				".log"

#define CMD_PROMT							"\nServer>"

#endif	//end of define _GAMESERVERDEF_H_