// UI.cpp
#include "UI.h"
#include "GameLogic.h"
#include "Game.h"

UI::UI(GameLogic* gameLogic, const wxString& title) : wxFrame(nullptr, wxID_ANY, title), gameLogic_(gameLogic) {
    // Create the UI elements
    panel_ = new wxPanel(this);
    sizer_ = new wxBoxSizer(wxVERTICAL);

    // Create the combat simulator UI
    createCombatSimulatorUI();

    // Set the sizer for the panel
    panel_->SetSizer(sizer_);
}

UI::~UI() {
    // Deallocate memory for UI elements
    delete panel_;
    delete sizer_;
    delete attackButton_;
    delete combatResultsTextCtrl_;
}

void UI::createCombatSimulatorUI() {
    // Create the attack button
    attackButton_ = new wxButton(panel_, wxID_ANY, "Attack");
    sizer_->Add(attackButton_, 0, wxALIGN_CENTER);

    // Create the combat results text control
    combatResultsTextCtrl_ = new wxTextCtrl(panel_, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sizer_->Add(combatResultsTextCtrl_, 1, wxEXPAND);

    // Connect the attack button click event
    Connect(wxEVT_BUTTON, (wxObjectEventFunction)&UI::handleAttackButtonClicked, this, attackButton_);
}

void UI::handleAttackButtonClicked(wxCommandEvent& event) {
    // Handle the attack button click
    gameLogic_->updateGameLogic();
    updateCombatResultsTextCtrl("Attack button clicked!");
}

void UI::updateCombatResultsTextCtrl(const wxString& text) {
    // Update the combat results text control
    combatResultsTextCtrl_->AppendText(text + "\n");
}