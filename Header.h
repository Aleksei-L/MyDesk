#pragma once

class MyProjectApp : public wxApp {
public:
	MyProjectApp();
	virtual ~MyProjectApp();
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
