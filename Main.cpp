#include <wx/wx.h>
#include "Header.h"

// �������������� ����������
bool MyDesk::OnInit() {
	// ������� ������� ���� ����������
	HelloWindow* mainFrame = new HelloWindow();

	// ���������� ���
	mainFrame->Show(true);

	// ��������� ����� ���������
	return true;
}

// ����������� ��������� ����
HelloWindow::HelloWindow() : wxFrame(nullptr, wxID_ANY, L"Hello World!") {
	hello = new wxStaticText(this, wxID_OK, wxT("What"), { 100, 50 }, { 250, 20 });
	helloButton = new wxButton(this, wxID_OK, wxT("Hello"), { 150, 100 });
	helloButton->Bind(wxEVT_BUTTON, &HelloWindow::OnClick, this);

	// ������� ����
	wxMenu* fileMenu = new wxMenu;

	// ��������� ����� "About" (� ����������), ������� ������ ���������� ��������� ������
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));

	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

	// ������ ��������� ��������� ���� � ������ ����...
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));

	// ... � ������������ � ������
	SetMenuBar(menuBar);
}

// ���������� ��������� ����
HelloWindow::~HelloWindow() {
	wxString goodbyemsg;

	goodbyemsg.Printf(wxT("See you later!"));

	wxMessageBox(goodbyemsg, wxT("Goodbye"), wxOK | wxICON_ERROR, this);
}

// ������� ������������ ��� ����� �� ������
void HelloWindow::OnClick(wxCommandEvent& event) {
	hello->SetLabelText(L"Hello World, I want to get off.");
	helloButton->Enable(false);
}

// ������� ������������ ��� ����� �� � ���������
void HelloWindow::OnAbout(wxCommandEvent& event) {
	wxString msg;

	msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);

	wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}

// ������� ������������ ��� ����� �� �����
void HelloWindow::OnExit(wxCommandEvent& event) {
	Close();
}

// ������� ��������� ��� HelloWindow
BEGIN_EVENT_TABLE(HelloWindow, wxFrame)
EVT_MENU(wxID_ABOUT, HelloWindow::OnAbout)
EVT_MENU(wxID_EXIT, HelloWindow::OnExit)
END_EVENT_TABLE()

IMPLEMENT_APP(MyDesk);
IMPLEMENT_WXWIN_MAIN_CONSOLE;
