#ifndef __GAME_H__
#define __GAME_H__
#include "JMDefs.h"
//#include "Render.h"
//#include "Player.h"
//#include "Dungeon.h"
//#include "DisplayText.h"
//#include "States.h"

class CRender;
class CDungeon;
class CPlayer;
class CDisplayText;
class CStateBase;
class CCmdState;
class CModState;
class CAIMgr;

class CGame
{
public:
	CGame();
	~CGame() { Quit(0); };

	JResult Init();
	bool Update(float fCurTime); // someday figure out why this doesn't work...
	void HandleEvents(int &isActive, int &done);
	void Draw();

	CRender *GetRender() { return m_pRender; };
	CDungeon *GetDungeon() { return m_pDungeon; };
	CPlayer *GetPlayer() { return m_pPlayer; };
	CDisplayText *GetMsgs() { return m_pMsgsDT; };
	CDisplayText *GetStats() { return m_pStatsDT; };
	CAIMgr *GetAIMgr() { return m_pAIMgr; };
	void Quit( int returncode );
	void SetState( int eNewState );
	CStateBase *GetGameState() { return m_pCurState; };
	
protected:
	CDungeon	*m_pDungeon;
	CPlayer		*m_pPlayer;
	CAIMgr		*m_pAIMgr;
	
	CDisplayText *m_pMsgsDT;
	CDisplayText *m_pStatsDT;
	
	CStateBase	 *m_pCurState;
	int			 m_eCurState;

	CCmdState	*m_pCmdState;
	CModState	*m_pModState;

private:
	CRender	*m_pRender;

	int m_dwNextTime;
};
#endif // __GAME_H__