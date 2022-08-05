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

HelloWindow::~HelloWindow() {
	//TODO msgbox
}

void HelloWindow::OnClick(wxCommandEvent& event) {
	hello->SetLabelText(L"Hello World, I want to get off.");
	helloButton->Enable(false);
}

IMPLEMENT_APP(MyDesk);
IMPLEMENT_WXWIN_MAIN_CONSOLE;
