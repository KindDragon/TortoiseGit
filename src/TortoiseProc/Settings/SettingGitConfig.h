// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2008-2013 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once

#include "SettingsPropPage.h"
#include "Tooltip.h"
#include "registry.h"
#include "afxwin.h"
#include "Git.h"
#include "GitSettings.h"

// CSettingGitConfig dialog

class CSettingGitConfig : public ISettingsPropPage, public CGitSettings
{
	DECLARE_DYNAMIC(CSettingGitConfig)

public:
	CSettingGitConfig();
	virtual ~CSettingGitConfig();
	UINT GetIconID() {return IDI_GITCONFIG;}
// Dialog Data
	enum { IDD = IDD_SETTINGIT_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();
	BOOL OnApply();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	virtual void LoadDataImpl(git_config * config);
	virtual BOOL SafeDataImpl(git_config * config);

	DECLARE_MESSAGE_MAP()

	afx_msg void OnChange();
	afx_msg void OnBnClickedEditsystemgitconfig();
	afx_msg void OnBnClickedViewsystemgitconfig();
	afx_msg void OnBnClickedEditglobalgitconfig();
	afx_msg void OnBnClickedEditglobalxdggitconfig();
	afx_msg void OnBnClickedEditlocalgitconfig();
	afx_msg void OnBnClickedEdittgitconfig();
	GITSETTINGS_RADIO_EVENT_HANDLE;

	bool	m_bNeedSave;
	CToolTips	m_tooltips;
	CString	m_UserName;
	CString	m_UserEmail;
	CString	m_UserSigningKey;
	BOOL	m_bAutoCrlf;
	BOOL	m_bQuotePath;
	CComboBox m_cSafeCrLf;
};
