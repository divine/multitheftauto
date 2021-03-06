/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/CMainConfig.h
*  PURPOSE:     XML-based main configuration file parser class
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Cecill Etheredge <>
*               Jax <>
*               Oliver Brown <>
*               Chris McArthur <>
*               Kevin Whiteside <>
*               Ed Lyons <>
*               lil_Toady <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

class CMainConfig;

#ifndef __CMAINCONFIG_H
#define __CMAINCONFIG_H

#include "CCommon.h"
#include "CLogger.h"
#include "CConsole.h"
#include "CXMLConfig.h"
#include <list>

#define MAX_MAP_NAME_LENGTH 64

class CMainConfig: public CXMLConfig
{
public:
                                    CMainConfig                     ( CConsole* pConsole, class CLuaManager* pLuaMain );

    bool                            Load                            ( const char* szFileName = NULL );
	bool							LoadExtended					( void );
    bool                            Save                            ( const char* szFileName = NULL );

	inline unsigned int				GetMTUSize						( void )		{ return m_uiMTUSize; };
    inline const std::string&       GetServerName                   ( void )        { return m_strServerName; };
    std::string                     GetServerIP                     ( void );
    unsigned short                  GetServerPort                   ( void );
    unsigned int                    GetMaxPlayers                   ( void );
    inline bool                     IsHTTPEnabled                   ( void )        { return m_bHTTPEnabled; };

    bool                            IsValidPassword                 ( const char* szPassword, unsigned int& cUnsupportedIndex );
    inline bool                     HasPassword                     ( void )        { return !m_strPassword.empty (); };
    inline const std::string&       GetPassword                     ( void )        { return m_strPassword; };
    void                            SetPassword                     ( const char* szPassword );

    inline bool                     GetASEEnabled                   ( void )        { return m_bAseEnabled; };
    unsigned short                  GetHTTPPort                     ( void );
    inline eHTTPDownloadType        GetHTTPDownloadType             ( void )        { return m_ucHTTPDownloadType; };
    inline const std::string&       GetHTTPDownloadURL              ( void )        { return m_strHTTPDownloadURL; };
    inline bool                     GetLogFileEnabled               ( void )        { return m_bLogFileEnabled; };
    inline const std::string&       GetLogFile                      ( void )        { return m_strLogFile; };
    inline bool                     GetAutoUpdateAntiCheatEnabled   ( void )        { return m_bAutoUpdateAntiCheatEnabled; };
    inline bool                     GetJoinFloodProtectionEnabled   ( void )        { return m_bJoinFloodProtectionEnabled; };
    inline bool                     GetScriptDebugLogEnabled        ( void )        { return m_bScriptDebugLogEnabled && !m_strScriptDebugLogFile.empty (); };
    inline const std::string&       GetScriptDebugLogFile           ( void )        { return m_strScriptDebugLogFile; };
    inline unsigned int             GetScriptDebugLogLevel          ( void )        { return m_uiScriptDebugLogLevel; };
    inline const std::string&       GetAccessControlListFile        ( void )        { return m_strAccessControlListFile; };
	inline bool                     GetAutoUpdateIncludedResourcesEnabled   ( void )        { return m_bAutoUpdateIncludedResources; };
	inline bool						GetDontBroadcastLan				( void )		{ return m_bDontBroadcastLan; };
	inline bool						GetSerialVerificationEnabled	( void )		{ return m_bVerifySerials; };

	inline unsigned short			GetFPSLimit						( void )		{ return m_usFPSLimit; };
	void							SetFPSLimit						( unsigned short usFPS );

    void                            SetCommandLineParser            ( CCommandLineParser* pCommandLineParser );

private:
    void                            RegisterCommand                 ( const char* szName, FCommandHandler* pFunction, bool bRestricted );

    CConsole*                       m_pConsole;
    CLuaManager*                    m_pLuaManager;
    CXMLNode*                       m_pRootNode;
    CCommandLineParser*             m_pCommandLineParser;

	unsigned int					m_uiMTUSize;
    std::string                     m_strServerIP;
    std::string                     m_strServerName;
    unsigned short                  m_usServerPort;
    unsigned int                    m_uiMaxPlayers;
    bool                            m_bHTTPEnabled;
    std::string                     m_strPassword;
    bool                            m_bAseEnabled;
	unsigned short					m_usHTTPPort;
    eHTTPDownloadType               m_ucHTTPDownloadType;
    std::string                     m_strHTTPDownloadURL;
    bool                            m_bLogFileEnabled;
    std::string                     m_strLogFile;
    bool                            m_bAutoUpdateAntiCheatEnabled;
    bool                            m_bJoinFloodProtectionEnabled;
    bool                            m_bScriptDebugLogEnabled;
    std::string                     m_strScriptDebugLogFile;
    unsigned int                    m_uiScriptDebugLogLevel;
    std::string                     m_strAccessControlListFile;
	bool							m_bAutoUpdateIncludedResources;
	bool							m_bVerifySerials;
	unsigned short					m_usFPSLimit;
	bool							m_bDontBroadcastLan;
};

#endif
