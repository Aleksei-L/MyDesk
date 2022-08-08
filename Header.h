#pragma once

// Основной класс приложения
class MyDesk : public wxApp {
public:
	virtual bool OnInit() override;
};

// Класс главного окна приложения
class HelloWindow : public wxFrame {
public:
	HelloWindow();
	virtual ~HelloWindow();
	void OnClick(wxCommandEvent& event);

	// Обработчики сообщений
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
private:
	// Этот класс перехватывает сообщения
	DECLARE_EVENT_TABLE()

	wxStaticText* hello;
	wxButton* helloButton;
};
