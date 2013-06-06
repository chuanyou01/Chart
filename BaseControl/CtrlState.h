#pragma once

class CCtrlState
{
public:
	CCtrlState(void);
	~CCtrlState(void);

	void Init();

	bool Show();
	void SubShow();
	void Hide();

	bool operator<(const CCtrlState& L1);
private:
	int 	m_nSetZindex;
	bool			m_isRelate;

	int		m_nCtrlId;
	int		m_nCurZindex;

};
