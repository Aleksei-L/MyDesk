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

// Конструктор основного окна
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

// Деструктор основного окна
HelloWindow::~HelloWindow() {
	wxString goodbyemsg;

	goodbyemsg.Printf(wxT("See you later!"));

	wxMessageBox(goodbyemsg, wxT("Goodbye"), wxOK | wxICON_ERROR, this);
}

// Функция вызывающаяся при клике на кнопку
void HelloWindow::OnClick(wxCommandEvent& event) {
	hello->SetLabelText(L"Hello World, I want to get off.");
	helloButton->Enable(false);
}

// Функция вызывающаяся при клике на О Программе
void HelloWindow::OnAbout(wxCommandEvent& event) {
	wxString msg;

	msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);

	wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}

// Функция вызывающаяся при клике на Выход
void HelloWindow::OnExit(wxCommandEvent& event) {
	Close();
}

// Таблица сообщений для HelloWindow
BEGIN_EVENT_TABLE(HelloWindow, wxFrame)
EVT_MENU(wxID_ABOUT, HelloWindow::OnAbout)
EVT_MENU(wxID_EXIT, HelloWindow::OnExit)
END_EVENT_TABLE()

IMPLEMENT_APP(MyDesk);
IMPLEMENT_WXWIN_MAIN_CONSOLE;
