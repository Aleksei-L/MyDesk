#pragma once

// �������� ����� ����������
class MyDesk : public wxApp {
public:
	virtual bool OnInit() override;
};

// ����� �������� ���� ����������
class HelloWindow : public wxFrame {
public:
	HelloWindow();
	virtual ~HelloWindow();
	void OnClick(wxCommandEvent& event);

	// ����������� ���������
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
private:
	// ���� ����� ������������� ���������
	DECLARE_EVENT_TABLE()

	wxStaticText* hello;
	wxButton* helloButton;
};
