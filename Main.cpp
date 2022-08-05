#include <wx/wx.h>
#include "Header.h"

// Инициализируем приложение
bool MyDesk::OnInit() {
	// Создаем главное окно приложения
	HelloWindow* mainFrame = new HelloWindow();

	// Показываем его
	mainFrame->Show(true);

	// Запускаем петлю сообщений
	return true;
}

HelloWindow::HelloWindow() : wxFrame(nullptr, wxID_ANY, L"Hello World!") {
	hello = new wxStaticText(this, wxID_OK, wxT("What"), { 100, 50 }, { 250, 20 });
	helloButton = new wxButton(this, wxID_OK, wxT("Hello"), { 150, 100 });
	helloButton->Bind(wxEVT_BUTTON, &HelloWindow::OnClick, this);

	// Создаем меню
	wxMenu* fileMenu = new wxMenu;

	// Добавляем пункт "About" (о приложении), который должен показывать маленькую помощь
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));

	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

	// Теперь добавляем созданное меню в строку меню...
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));

	// ... и присоединяем к фрейму
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
