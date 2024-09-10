#pragma once
// UI.h
#ifndef UI_H
#define UI_H

#include <wx/wx.h>
#include "GameLogic.h"

class UI : public wxFrame {
public:
    UI(GameLogic* gameLogic, const wxString& title);
    ~UI();

    // Create the combat simulator UI
    void createCombatSimulatorUI();

    // Handle the attack button click
    void handleAttackButtonClicked(wxCommandEvent& event);
    // Update the combat results text control
    void updateCombatResultsTextCtrl(const wxString& text);

private:
    // Game logic object
    GameLogic* gameLogic_;

    // UI elements
    wxPanel* panel_;
    wxBoxSizer* sizer_;
    wxButton* attackButton_;
    wxTextCtrl* combatResultsTextCtrl_;
};

#endif // UI_H
