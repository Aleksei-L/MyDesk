#pragma once

// Основной класс приложения
class MyDesk : public wxApp {
public:
	virtual bool OnInit() override;
};

class HelloWindow : public wxFrame {
public:
	HelloWindow();
	virtual ~HelloWindow();
	void OnClick(wxCommandEvent& event);
private:
	wxStaticText* hello;
	wxButton* helloButton;
};
