#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <msclr/marshal_cppstd.h>

namespace HangMan {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            InitializeGame();
            AsociazaEvenimenteClick();
            ActualizeazaScor();
            panelSpanzuratoare->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelSpanzuratoare_Paint);
            cuvinteAnimale = gcnew cli::array<System::String^> { "CAINE", "PISICA", "ELEFANT", "GIRAFA", "DELFIN", "RINOCER", "CROCODIL", "HIPOPOTAM", "CARACATITA", "ORNITORINC"  };
            cuvinteCulori = gcnew cli::array<System::String^> { "ROSU", "VERDE", "VIOLET", "NEGRU", "GALBEN", "TURCOAZ", "ALBASTRU", "PORTOCALIU", "AQUAMARIN", "CIOCOLATA" };
            cuvinteMancare = gcnew cli::array<System::String^> { "PAINE", "PIZZA", "SUSHI", "OMLETA", "SPAGHETE",  "SARMALE", "CHIFTELE", "TOCANITA", "FRIPTURA" ,"TOCHITURA"};
            cuvinteCorp = gcnew cli::array<System::String^> { "GURA","OCHI","UMAR","PICIOR","GLEZNE", "STOMAC",   "URECHE", "TORACE",  "ABDOMEN",  "GENUNCHI" };
            cuvinteMobila = gcnew cli::array<System::String^> {"MASA", "SCAUN","DULAP","TABURET",  "BIROU",  "COMODA", "CANAPEA","FOTOLIU","ETAJERA" , "BIBLIOTECA"};
            cuvinteMunca = gcnew cli::array<System::String^> { "MEDIC", "ACTOR","INGINER", "POMPIER","PROFESOR", "POLITIST", "MUZICIAN", "JURNALIST","ARHITECT","PROGRAMATOR"};
            cuvantIndex = 0;
            cuvinteGhicite = 0;
            cuvinteNeghicite = 0;
            scor = 0;
            streak = 0;
            hintFolosite = false;
            flpMeniu->Visible = true;
            flpDomeniu->Visible = false;
            flpJoc->Visible = false;
            flpScor->Visible = false;
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        }

    private:
        void AsociazaEvenimenteClick()
        {
            this->btA->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btB->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btC->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btD->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btE->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btF->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btG->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btH->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btI->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btJ->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btK->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btL->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btM->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btN->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btO->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btP->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btQ->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btR->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btS->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btT->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btU->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btV->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btW->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btX->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btY->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
            this->btZ->Click += gcnew System::EventHandler(this, &MainForm::VerificaLitera);
        }

            
    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::FlowLayoutPanel^ flpMeniu;

    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Button^ btJoaca;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::Button^ btScor;

    private: System::Windows::Forms::Panel^ panel6;
    private: System::Windows::Forms::Panel^ panel7;
    private: System::Windows::Forms::Button^ btIesire;
    private: System::Windows::Forms::FlowLayoutPanel^ flpDomeniu;
    private: System::Windows::Forms::Panel^ panel8;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Panel^ panel9;
    private: System::Windows::Forms::Panel^ panel10;
    private: System::Windows::Forms::Button^ btAnimale;
    private: System::Windows::Forms::Panel^ panel11;
    private: System::Windows::Forms::Panel^ panel12;
    private: System::Windows::Forms::Button^ btCulori;
    private: System::Windows::Forms::Panel^ panel13;
    private: System::Windows::Forms::Panel^ panel14;
    private: System::Windows::Forms::Button^ btMancare;
    private: System::Windows::Forms::Panel^ panel15;
    private: System::Windows::Forms::Panel^ panel16;
    private: System::Windows::Forms::Button^ btCorp;
    private: System::Windows::Forms::Panel^ panel17;
    private: System::Windows::Forms::Panel^ panel18;
    private: System::Windows::Forms::Button^ btMobila;


    private: System::Windows::Forms::Panel^ panel19;
    private: System::Windows::Forms::Panel^ panel20;
    private: System::Windows::Forms::Button^ btMunca;
    private: System::Windows::Forms::Panel^ panel21;
    private: System::Windows::Forms::Panel^ panel22;
    private: System::Windows::Forms::Button^ btBack;
    private: System::Windows::Forms::FlowLayoutPanel^ flpJoc;

    private: System::Windows::Forms::Panel^ panelCuvant;
    private: System::Windows::Forms::Panel^ panelScor;

    private: System::Windows::Forms::Panel^ panel26;
    private: System::Windows::Forms::Button^ btA;


    private: System::Windows::Forms::Panel^ panelSpanzuratoare;
    private: System::Windows::Forms::Button^ btF;

    private: System::Windows::Forms::Button^ btE;

    private: System::Windows::Forms::Button^ btD;

    private: System::Windows::Forms::Button^ btC;

    private: System::Windows::Forms::Button^ btB;
    private: System::Windows::Forms::Button^ btZ;

    private: System::Windows::Forms::Button^ btY;

    private: System::Windows::Forms::Button^ btX;

    private: System::Windows::Forms::Button^ btW;

    private: System::Windows::Forms::Button^ btV;

    private: System::Windows::Forms::Button^ btU;

    private: System::Windows::Forms::Button^ btT;

    private: System::Windows::Forms::Button^ btS;

    private: System::Windows::Forms::Button^ btR;

    private: System::Windows::Forms::Button^ btQ;

    private: System::Windows::Forms::Button^ btP;

    private: System::Windows::Forms::Button^ btO;

    private: System::Windows::Forms::Button^ btN;

    private: System::Windows::Forms::Button^ btM;

    private: System::Windows::Forms::Button^ btL;

    private: System::Windows::Forms::Button^ btK;

    private: System::Windows::Forms::Button^ btJ;

    private: System::Windows::Forms::Button^ btI;

    private: System::Windows::Forms::Button^ btH;

    private: System::Windows::Forms::Button^ btG;
    private: System::Windows::Forms::Panel^ panel23;
    private: System::Windows::Forms::Panel^ panel24;
    private: System::Windows::Forms::Button^ btHome;

    private: System::Windows::Forms::Panel^ panel25;
    private: System::Windows::Forms::Panel^ panel27;
    private: System::Windows::Forms::Button^ btHint;

    

    private:
        int cuvantIndex;
        int cuvinteGhicite;
        int cuvinteNeghicite;
        cli::array<System::String^>^ cuvinteAnimale;
        cli::array<System::String^>^ cuvinteCulori;
        cli::array<System::String^>^ cuvinteMancare;
        cli::array<System::String^>^ cuvinteCorp;
        cli::array<System::String^>^ cuvinteMobila;
        cli::array<System::String^>^ cuvinteMunca;
        cli::array<System::String^>^ cuvinteCurente;
        System::String^ cuvantCurent;
        System::String^ cuvantAfisat;
        System::String^ domeniuSelectat;
        int greseli;
        int scor = 0;
        int streak;
        bool hintFolosite;
    private: System::Windows::Forms::Label^ labelCuvant;
    private: System::Windows::Forms::Label^ labelScor;
private: System::Windows::Forms::FlowLayoutPanel^ flpScor;
private: System::Windows::Forms::Panel^ panel28;
private: System::Windows::Forms::Label^ lbTitluScor;
private: System::Windows::Forms::Panel^ panel29;
private: System::Windows::Forms::Panel^ panel30;
private: System::Windows::Forms::Button^ btHome2;
private: System::Windows::Forms::Panel^ panelAdaugare;
private: System::Windows::Forms::Panel^ panelTabel;
private: System::Windows::Forms::Button^ btAdauga;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ labelScorul;
private: System::Windows::Forms::TextBox^ txtNume;
private: System::Windows::Forms::DataGridView^ dgvScor;





       System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->flpMeniu = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->btJoaca = (gcnew System::Windows::Forms::Button());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->btScor = (gcnew System::Windows::Forms::Button());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->btIesire = (gcnew System::Windows::Forms::Button());
            this->flpDomeniu = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->panel21 = (gcnew System::Windows::Forms::Panel());
            this->panel22 = (gcnew System::Windows::Forms::Panel());
            this->btBack = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->btAnimale = (gcnew System::Windows::Forms::Button());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->btCulori = (gcnew System::Windows::Forms::Button());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->btMancare = (gcnew System::Windows::Forms::Button());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
            this->btCorp = (gcnew System::Windows::Forms::Button());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->btMobila = (gcnew System::Windows::Forms::Button());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->panel20 = (gcnew System::Windows::Forms::Panel());
            this->btMunca = (gcnew System::Windows::Forms::Button());
            this->flpJoc = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->panelCuvant = (gcnew System::Windows::Forms::Panel());
            this->labelCuvant = (gcnew System::Windows::Forms::Label());
            this->panel23 = (gcnew System::Windows::Forms::Panel());
            this->panel24 = (gcnew System::Windows::Forms::Panel());
            this->btHome = (gcnew System::Windows::Forms::Button());
            this->panelScor = (gcnew System::Windows::Forms::Panel());
            this->labelScor = (gcnew System::Windows::Forms::Label());
            this->panel26 = (gcnew System::Windows::Forms::Panel());
            this->panel25 = (gcnew System::Windows::Forms::Panel());
            this->panel27 = (gcnew System::Windows::Forms::Panel());
            this->btHint = (gcnew System::Windows::Forms::Button());
            this->btZ = (gcnew System::Windows::Forms::Button());
            this->btY = (gcnew System::Windows::Forms::Button());
            this->btX = (gcnew System::Windows::Forms::Button());
            this->btW = (gcnew System::Windows::Forms::Button());
            this->btV = (gcnew System::Windows::Forms::Button());
            this->btU = (gcnew System::Windows::Forms::Button());
            this->btT = (gcnew System::Windows::Forms::Button());
            this->btS = (gcnew System::Windows::Forms::Button());
            this->btR = (gcnew System::Windows::Forms::Button());
            this->btQ = (gcnew System::Windows::Forms::Button());
            this->btP = (gcnew System::Windows::Forms::Button());
            this->btO = (gcnew System::Windows::Forms::Button());
            this->btN = (gcnew System::Windows::Forms::Button());
            this->btM = (gcnew System::Windows::Forms::Button());
            this->btL = (gcnew System::Windows::Forms::Button());
            this->btK = (gcnew System::Windows::Forms::Button());
            this->btJ = (gcnew System::Windows::Forms::Button());
            this->btI = (gcnew System::Windows::Forms::Button());
            this->btH = (gcnew System::Windows::Forms::Button());
            this->btG = (gcnew System::Windows::Forms::Button());
            this->btF = (gcnew System::Windows::Forms::Button());
            this->btE = (gcnew System::Windows::Forms::Button());
            this->btD = (gcnew System::Windows::Forms::Button());
            this->btC = (gcnew System::Windows::Forms::Button());
            this->btB = (gcnew System::Windows::Forms::Button());
            this->btA = (gcnew System::Windows::Forms::Button());
            this->panelSpanzuratoare = (gcnew System::Windows::Forms::Panel());
            this->flpScor = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->panel28 = (gcnew System::Windows::Forms::Panel());
            this->lbTitluScor = (gcnew System::Windows::Forms::Label());
            this->panel29 = (gcnew System::Windows::Forms::Panel());
            this->panel30 = (gcnew System::Windows::Forms::Panel());
            this->btHome2 = (gcnew System::Windows::Forms::Button());
            this->panelAdaugare = (gcnew System::Windows::Forms::Panel());
            this->txtNume = (gcnew System::Windows::Forms::TextBox());
            this->btAdauga = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->labelScorul = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->panelTabel = (gcnew System::Windows::Forms::Panel());
            this->dgvScor = (gcnew System::Windows::Forms::DataGridView());
            this->flpMeniu->SuspendLayout();
            this->panel1->SuspendLayout();
            this->panel2->SuspendLayout();
            this->panel3->SuspendLayout();
            this->panel4->SuspendLayout();
            this->panel5->SuspendLayout();
            this->panel6->SuspendLayout();
            this->panel7->SuspendLayout();
            this->flpDomeniu->SuspendLayout();
            this->panel8->SuspendLayout();
            this->panel21->SuspendLayout();
            this->panel22->SuspendLayout();
            this->panel9->SuspendLayout();
            this->panel10->SuspendLayout();
            this->panel11->SuspendLayout();
            this->panel12->SuspendLayout();
            this->panel13->SuspendLayout();
            this->panel14->SuspendLayout();
            this->panel15->SuspendLayout();
            this->panel16->SuspendLayout();
            this->panel17->SuspendLayout();
            this->panel18->SuspendLayout();
            this->panel19->SuspendLayout();
            this->panel20->SuspendLayout();
            this->flpJoc->SuspendLayout();
            this->panelCuvant->SuspendLayout();
            this->panel23->SuspendLayout();
            this->panel24->SuspendLayout();
            this->panelScor->SuspendLayout();
            this->panel26->SuspendLayout();
            this->panel25->SuspendLayout();
            this->panel27->SuspendLayout();
            this->flpScor->SuspendLayout();
            this->panel28->SuspendLayout();
            this->panel29->SuspendLayout();
            this->panel30->SuspendLayout();
            this->panelAdaugare->SuspendLayout();
            this->panelTabel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvScor))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(55, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(283, 46);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Spânzuratoarea";
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // flpMeniu
            // 
            this->flpMeniu->BackColor = System::Drawing::Color::Transparent;
            this->flpMeniu->Controls->Add(this->panel1);
            this->flpMeniu->Controls->Add(this->panel2);
            this->flpMeniu->Controls->Add(this->panel4);
            this->flpMeniu->Controls->Add(this->panel6);
            this->flpMeniu->Location = System::Drawing::Point(234, 12);
            this->flpMeniu->Name = L"flpMeniu";
            this->flpMeniu->Size = System::Drawing::Size(393, 408);
            this->flpMeniu->TabIndex = 1;
            // 
            // panel1
            // 
            this->panel1->Controls->Add(this->label1);
            this->panel1->Location = System::Drawing::Point(3, 3);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(390, 100);
            this->panel1->TabIndex = 1;
            // 
            // panel2
            // 
            this->panel2->Controls->Add(this->panel3);
            this->panel2->Location = System::Drawing::Point(3, 109);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(390, 100);
            this->panel2->TabIndex = 2;
            // 
            // panel3
            // 
            this->panel3->Controls->Add(this->btJoaca);
            this->panel3->Location = System::Drawing::Point(126, 0);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(130, 100);
            this->panel3->TabIndex = 3;
            // 
            // btJoaca
            // 
            this->btJoaca->BackColor = System::Drawing::Color::Transparent;
            this->btJoaca->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btJoaca->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btJoaca->Location = System::Drawing::Point(-9, -15);
            this->btJoaca->Name = L"btJoaca";
            this->btJoaca->Size = System::Drawing::Size(142, 131);
            this->btJoaca->TabIndex = 0;
            this->btJoaca->Text = L"Joaca";
            this->btJoaca->UseVisualStyleBackColor = false;
            this->btJoaca->Click += gcnew System::EventHandler(this, &MainForm::btJoaca_Click);
            // 
            // panel4
            // 
            this->panel4->Controls->Add(this->panel5);
            this->panel4->Location = System::Drawing::Point(3, 215);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(390, 100);
            this->panel4->TabIndex = 3;
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->btScor);
            this->panel5->Location = System::Drawing::Point(126, 0);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(130, 100);
            this->panel5->TabIndex = 3;
            // 
            // btScor
            // 
            this->btScor->BackColor = System::Drawing::Color::Transparent;
            this->btScor->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btScor->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btScor->Location = System::Drawing::Point(-9, -15);
            this->btScor->Name = L"btScor";
            this->btScor->Size = System::Drawing::Size(142, 131);
            this->btScor->TabIndex = 0;
            this->btScor->Text = L"Scor";
            this->btScor->UseVisualStyleBackColor = false;
            this->btScor->Click += gcnew System::EventHandler(this, &MainForm::btScor_Click);
            // 
            // panel6
            // 
            this->panel6->Controls->Add(this->panel7);
            this->panel6->Location = System::Drawing::Point(3, 321);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(390, 100);
            this->panel6->TabIndex = 3;
            // 
            // panel7
            // 
            this->panel7->Controls->Add(this->btIesire);
            this->panel7->Location = System::Drawing::Point(126, 0);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(130, 100);
            this->panel7->TabIndex = 3;
            // 
            // btIesire
            // 
            this->btIesire->BackColor = System::Drawing::Color::Transparent;
            this->btIesire->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btIesire->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btIesire->Location = System::Drawing::Point(-9, -15);
            this->btIesire->Name = L"btIesire";
            this->btIesire->Size = System::Drawing::Size(142, 131);
            this->btIesire->TabIndex = 0;
            this->btIesire->Text = L"Iesire";
            this->btIesire->UseVisualStyleBackColor = false;
            this->btIesire->Click += gcnew System::EventHandler(this, &MainForm::btIesire_Click);
            // 
            // flpDomeniu
            // 
            this->flpDomeniu->BackColor = System::Drawing::Color::Transparent;
            this->flpDomeniu->Controls->Add(this->panel8);
            this->flpDomeniu->Controls->Add(this->panel9);
            this->flpDomeniu->Controls->Add(this->panel11);
            this->flpDomeniu->Controls->Add(this->panel13);
            this->flpDomeniu->Controls->Add(this->panel15);
            this->flpDomeniu->Controls->Add(this->panel17);
            this->flpDomeniu->Controls->Add(this->panel19);
            this->flpDomeniu->Location = System::Drawing::Point(0, 10);
            this->flpDomeniu->Name = L"flpDomeniu";
            this->flpDomeniu->Size = System::Drawing::Size(888, 406);
            this->flpDomeniu->TabIndex = 2;
            // 
            // panel8
            // 
            this->panel8->Controls->Add(this->panel21);
            this->panel8->Controls->Add(this->label2);
            this->panel8->Location = System::Drawing::Point(3, 3);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(884, 100);
            this->panel8->TabIndex = 3;
            // 
            // panel21
            // 
            this->panel21->Controls->Add(this->panel22);
            this->panel21->Location = System::Drawing::Point(40, 0);
            this->panel21->Name = L"panel21";
            this->panel21->Size = System::Drawing::Size(168, 100);
            this->panel21->TabIndex = 6;
            // 
            // panel22
            // 
            this->panel22->Controls->Add(this->btBack);
            this->panel22->Location = System::Drawing::Point(19, 0);
            this->panel22->Name = L"panel22";
            this->panel22->Size = System::Drawing::Size(130, 100);
            this->panel22->TabIndex = 3;
            // 
            // btBack
            // 
            this->btBack->BackColor = System::Drawing::Color::Transparent;
            this->btBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btBack->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btBack.Image")));
            this->btBack->Location = System::Drawing::Point(-13, -13);
            this->btBack->Name = L"btBack";
            this->btBack->Size = System::Drawing::Size(150, 115);
            this->btBack->TabIndex = 0;
            this->btBack->UseVisualStyleBackColor = false;
            this->btBack->Click += gcnew System::EventHandler(this, &MainForm::btBack_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(262, 12);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(327, 46);
            this->label2->TabIndex = 0;
            this->label2->Text = L"Selectati domeniul";
            this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // panel9
            // 
            this->panel9->Controls->Add(this->panel10);
            this->panel9->Location = System::Drawing::Point(3, 109);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(280, 100);
            this->panel9->TabIndex = 3;
            // 
            // panel10
            // 
            this->panel10->Controls->Add(this->btAnimale);
            this->panel10->Location = System::Drawing::Point(68, 0);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(130, 100);
            this->panel10->TabIndex = 3;
            // 
            // btAnimale
            // 
            this->btAnimale->BackColor = System::Drawing::Color::Transparent;
            this->btAnimale->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btAnimale->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btAnimale->Location = System::Drawing::Point(-10, -15);
            this->btAnimale->Name = L"btAnimale";
            this->btAnimale->Size = System::Drawing::Size(150, 117);
            this->btAnimale->TabIndex = 0;
            this->btAnimale->Text = L"Animale";
            this->btAnimale->UseVisualStyleBackColor = false;
            this->btAnimale->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // panel11
            // 
            this->panel11->Controls->Add(this->panel12);
            this->panel11->Location = System::Drawing::Point(289, 109);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(281, 100);
            this->panel11->TabIndex = 4;
            // 
            // panel12
            // 
            this->panel12->Controls->Add(this->btCulori);
            this->panel12->Location = System::Drawing::Point(77, 0);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(130, 100);
            this->panel12->TabIndex = 3;
            // 
            // btCulori
            // 
            this->btCulori->BackColor = System::Drawing::Color::Transparent;
            this->btCulori->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btCulori->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btCulori->Location = System::Drawing::Point(-9, -15);
            this->btCulori->Name = L"btCulori";
            this->btCulori->Size = System::Drawing::Size(150, 117);
            this->btCulori->TabIndex = 0;
            this->btCulori->Text = L"Culori";
            this->btCulori->UseVisualStyleBackColor = false;
            this->btCulori->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // panel13
            // 
            this->panel13->Controls->Add(this->panel14);
            this->panel13->Location = System::Drawing::Point(576, 109);
            this->panel13->Name = L"panel13";
            this->panel13->Size = System::Drawing::Size(301, 100);
            this->panel13->TabIndex = 5;
            // 
            // panel14
            // 
            this->panel14->Controls->Add(this->btMancare);
            this->panel14->Location = System::Drawing::Point(87, 0);
            this->panel14->Name = L"panel14";
            this->panel14->Size = System::Drawing::Size(130, 100);
            this->panel14->TabIndex = 3;
            // 
            // btMancare
            // 
            this->btMancare->BackColor = System::Drawing::Color::Transparent;
            this->btMancare->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btMancare->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btMancare->Location = System::Drawing::Point(-9, -15);
            this->btMancare->Name = L"btMancare";
            this->btMancare->Size = System::Drawing::Size(150, 117);
            this->btMancare->TabIndex = 0;
            this->btMancare->Text = L"Mancare";
            this->btMancare->UseVisualStyleBackColor = false;
            this->btMancare->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // panel15
            // 
            this->panel15->Controls->Add(this->panel16);
            this->panel15->Location = System::Drawing::Point(3, 215);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(280, 100);
            this->panel15->TabIndex = 6;
            // 
            // panel16
            // 
            this->panel16->Controls->Add(this->btCorp);
            this->panel16->Location = System::Drawing::Point(68, 0);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(130, 100);
            this->panel16->TabIndex = 3;
            // 
            // btCorp
            // 
            this->btCorp->BackColor = System::Drawing::Color::Transparent;
            this->btCorp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btCorp->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btCorp->Location = System::Drawing::Point(-10, -13);
            this->btCorp->Name = L"btCorp";
            this->btCorp->Size = System::Drawing::Size(150, 129);
            this->btCorp->TabIndex = 0;
            this->btCorp->Text = L"Corpul uman";
            this->btCorp->UseVisualStyleBackColor = false;
            this->btCorp->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // panel17
            // 
            this->panel17->Controls->Add(this->panel18);
            this->panel17->Location = System::Drawing::Point(289, 215);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(281, 100);
            this->panel17->TabIndex = 6;
            // 
            // panel18
            // 
            this->panel18->Controls->Add(this->btMobila);
            this->panel18->Location = System::Drawing::Point(91, 0);
            this->panel18->Name = L"panel18";
            this->panel18->Size = System::Drawing::Size(110, 100);
            this->panel18->TabIndex = 3;
            // 
            // btMobila
            // 
            this->btMobila->BackColor = System::Drawing::Color::Transparent;
            this->btMobila->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btMobila->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btMobila->Location = System::Drawing::Point(-26, -11);
            this->btMobila->Name = L"btMobila";
            this->btMobila->Size = System::Drawing::Size(150, 129);
            this->btMobila->TabIndex = 0;
            this->btMobila->Text = L"Mobila";
            this->btMobila->UseVisualStyleBackColor = false;
            this->btMobila->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // panel19
            // 
            this->panel19->Controls->Add(this->panel20);
            this->panel19->Location = System::Drawing::Point(576, 215);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(301, 100);
            this->panel19->TabIndex = 7;
            // 
            // panel20
            // 
            this->panel20->Controls->Add(this->btMunca);
            this->panel20->Location = System::Drawing::Point(87, 0);
            this->panel20->Name = L"panel20";
            this->panel20->Size = System::Drawing::Size(130, 100);
            this->panel20->TabIndex = 3;
            // 
            // btMunca
            // 
            this->btMunca->BackColor = System::Drawing::Color::Transparent;
            this->btMunca->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btMunca->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btMunca->Location = System::Drawing::Point(-9, -13);
            this->btMunca->Name = L"btMunca";
            this->btMunca->Size = System::Drawing::Size(150, 129);
            this->btMunca->TabIndex = 0;
            this->btMunca->Text = L"Locuri de munca";
            this->btMunca->UseVisualStyleBackColor = false;
            this->btMunca->Click += gcnew System::EventHandler(this, &MainForm::SelecteazaDomeniu);
            // 
            // flpJoc
            // 
            this->flpJoc->BackColor = System::Drawing::Color::Transparent;
            this->flpJoc->Controls->Add(this->panelCuvant);
            this->flpJoc->Controls->Add(this->panel26);
            this->flpJoc->Controls->Add(this->panelSpanzuratoare);
            this->flpJoc->Location = System::Drawing::Point(0, 10);
            this->flpJoc->Name = L"flpJoc";
            this->flpJoc->Size = System::Drawing::Size(888, 406);
            this->flpJoc->TabIndex = 3;
            // 
            // panelCuvant
            // 
            this->panelCuvant->Controls->Add(this->labelCuvant);
            this->panelCuvant->Controls->Add(this->panel23);
            this->panelCuvant->Controls->Add(this->panelScor);
            this->panelCuvant->Location = System::Drawing::Point(3, 3);
            this->panelCuvant->Name = L"panelCuvant";
            this->panelCuvant->Size = System::Drawing::Size(884, 73);
            this->panelCuvant->TabIndex = 3;
            // 
            // labelCuvant
            // 
            this->labelCuvant->AutoSize = true;
            this->labelCuvant->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->labelCuvant->Location = System::Drawing::Point(344, 5);
            this->labelCuvant->Name = L"labelCuvant";
            this->labelCuvant->Size = System::Drawing::Size(117, 46);
            this->labelCuvant->TabIndex = 8;
            this->labelCuvant->Text = L"label3";
            // 
            // panel23
            // 
            this->panel23->Controls->Add(this->panel24);
            this->panel23->Location = System::Drawing::Point(3, 3);
            this->panel23->Name = L"panel23";
            this->panel23->Size = System::Drawing::Size(74, 62);
            this->panel23->TabIndex = 7;
            // 
            // panel24
            // 
            this->panel24->Controls->Add(this->btHome);
            this->panel24->Location = System::Drawing::Point(19, 0);
            this->panel24->Name = L"panel24";
            this->panel24->Size = System::Drawing::Size(130, 100);
            this->panel24->TabIndex = 3;
            // 
            // btHome
            // 
            this->btHome->BackColor = System::Drawing::Color::Transparent;
            this->btHome->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btHome->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btHome->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btHome.Image")));
            this->btHome->Location = System::Drawing::Point(-36, -20);
            this->btHome->Name = L"btHome";
            this->btHome->Size = System::Drawing::Size(107, 97);
            this->btHome->TabIndex = 0;
            this->btHome->UseVisualStyleBackColor = false;
            this->btHome->Click += gcnew System::EventHandler(this, &MainForm::BtHome_Click);
            // 
            // panelScor
            // 
            this->panelScor->Controls->Add(this->labelScor);
            this->panelScor->Location = System::Drawing::Point(713, 0);
            this->panelScor->Name = L"panelScor";
            this->panelScor->Size = System::Drawing::Size(168, 73);
            this->panelScor->TabIndex = 6;
            // 
            // labelScor
            // 
            this->labelScor->AutoSize = true;
            this->labelScor->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->labelScor->Location = System::Drawing::Point(17, 3);
            this->labelScor->Name = L"labelScor";
            this->labelScor->Size = System::Drawing::Size(64, 24);
            this->labelScor->TabIndex = 9;
            this->labelScor->Text = L"label3";
            // 
            // panel26
            // 
            this->panel26->Controls->Add(this->panel25);
            this->panel26->Controls->Add(this->btZ);
            this->panel26->Controls->Add(this->btY);
            this->panel26->Controls->Add(this->btX);
            this->panel26->Controls->Add(this->btW);
            this->panel26->Controls->Add(this->btV);
            this->panel26->Controls->Add(this->btU);
            this->panel26->Controls->Add(this->btT);
            this->panel26->Controls->Add(this->btS);
            this->panel26->Controls->Add(this->btR);
            this->panel26->Controls->Add(this->btQ);
            this->panel26->Controls->Add(this->btP);
            this->panel26->Controls->Add(this->btO);
            this->panel26->Controls->Add(this->btN);
            this->panel26->Controls->Add(this->btM);
            this->panel26->Controls->Add(this->btL);
            this->panel26->Controls->Add(this->btK);
            this->panel26->Controls->Add(this->btJ);
            this->panel26->Controls->Add(this->btI);
            this->panel26->Controls->Add(this->btH);
            this->panel26->Controls->Add(this->btG);
            this->panel26->Controls->Add(this->btF);
            this->panel26->Controls->Add(this->btE);
            this->panel26->Controls->Add(this->btD);
            this->panel26->Controls->Add(this->btC);
            this->panel26->Controls->Add(this->btB);
            this->panel26->Controls->Add(this->btA);
            this->panel26->Location = System::Drawing::Point(3, 82);
            this->panel26->Name = L"panel26";
            this->panel26->Size = System::Drawing::Size(546, 324);
            this->panel26->TabIndex = 3;
            // 
            // panel25
            // 
            this->panel25->Controls->Add(this->panel27);
            this->panel25->Location = System::Drawing::Point(3, 259);
            this->panel25->Name = L"panel25";
            this->panel25->Size = System::Drawing::Size(74, 62);
            this->panel25->TabIndex = 8;
            // 
            // panel27
            // 
            this->panel27->Controls->Add(this->btHint);
            this->panel27->Location = System::Drawing::Point(19, 0);
            this->panel27->Name = L"panel27";
            this->panel27->Size = System::Drawing::Size(130, 100);
            this->panel27->TabIndex = 3;
            // 
            // btHint
            // 
            this->btHint->BackColor = System::Drawing::Color::Transparent;
            this->btHint->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btHint->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btHint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btHint.Image")));
            this->btHint->Location = System::Drawing::Point(-36, -10);
            this->btHint->Name = L"btHint";
            this->btHint->Size = System::Drawing::Size(107, 87);
            this->btHint->TabIndex = 0;
            this->btHint->UseVisualStyleBackColor = false;
            this->btHint->Click += gcnew System::EventHandler(this, &MainForm::Hint);
            // 
            // btZ
            // 
            this->btZ->BackColor = System::Drawing::Color::Transparent;
            this->btZ->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btZ->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btZ->Location = System::Drawing::Point(170, 216);
            this->btZ->Name = L"btZ";
            this->btZ->Size = System::Drawing::Size(45, 41);
            this->btZ->TabIndex = 25;
            this->btZ->Text = L"Z";
            this->btZ->UseVisualStyleBackColor = false;
            // 
            // btY
            // 
            this->btY->BackColor = System::Drawing::Color::Transparent;
            this->btY->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btY->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btY->Location = System::Drawing::Point(119, 216);
            this->btY->Name = L"btY";
            this->btY->Size = System::Drawing::Size(45, 41);
            this->btY->TabIndex = 24;
            this->btY->Text = L"Y";
            this->btY->UseVisualStyleBackColor = false;
            // 
            // btX
            // 
            this->btX->BackColor = System::Drawing::Color::Transparent;
            this->btX->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btX->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btX->Location = System::Drawing::Point(374, 169);
            this->btX->Name = L"btX";
            this->btX->Size = System::Drawing::Size(45, 41);
            this->btX->TabIndex = 23;
            this->btX->Text = L"X";
            this->btX->UseVisualStyleBackColor = false;
            // 
            // btW
            // 
            this->btW->BackColor = System::Drawing::Color::Transparent;
            this->btW->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btW->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btW->Location = System::Drawing::Point(323, 169);
            this->btW->Name = L"btW";
            this->btW->Size = System::Drawing::Size(45, 41);
            this->btW->TabIndex = 22;
            this->btW->Text = L"W";
            this->btW->UseVisualStyleBackColor = false;
            // 
            // btV
            // 
            this->btV->BackColor = System::Drawing::Color::Transparent;
            this->btV->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btV->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btV->Location = System::Drawing::Point(272, 169);
            this->btV->Name = L"btV";
            this->btV->Size = System::Drawing::Size(45, 41);
            this->btV->TabIndex = 21;
            this->btV->Text = L"V";
            this->btV->UseVisualStyleBackColor = false;
            // 
            // btU
            // 
            this->btU->BackColor = System::Drawing::Color::Transparent;
            this->btU->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btU->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btU->Location = System::Drawing::Point(221, 169);
            this->btU->Name = L"btU";
            this->btU->Size = System::Drawing::Size(45, 41);
            this->btU->TabIndex = 20;
            this->btU->Text = L"U";
            this->btU->UseVisualStyleBackColor = false;
            // 
            // btT
            // 
            this->btT->BackColor = System::Drawing::Color::Transparent;
            this->btT->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btT->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btT->Location = System::Drawing::Point(170, 169);
            this->btT->Name = L"btT";
            this->btT->Size = System::Drawing::Size(45, 41);
            this->btT->TabIndex = 19;
            this->btT->Text = L"T";
            this->btT->UseVisualStyleBackColor = false;
            // 
            // btS
            // 
            this->btS->BackColor = System::Drawing::Color::Transparent;
            this->btS->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btS->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btS->Location = System::Drawing::Point(119, 169);
            this->btS->Name = L"btS";
            this->btS->Size = System::Drawing::Size(45, 41);
            this->btS->TabIndex = 18;
            this->btS->Text = L"S";
            this->btS->UseVisualStyleBackColor = false;
            // 
            // btR
            // 
            this->btR->BackColor = System::Drawing::Color::Transparent;
            this->btR->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btR->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btR->Location = System::Drawing::Point(374, 122);
            this->btR->Name = L"btR";
            this->btR->Size = System::Drawing::Size(45, 41);
            this->btR->TabIndex = 17;
            this->btR->Text = L"R";
            this->btR->UseVisualStyleBackColor = false;
            // 
            // btQ
            // 
            this->btQ->BackColor = System::Drawing::Color::Transparent;
            this->btQ->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btQ->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btQ->Location = System::Drawing::Point(323, 122);
            this->btQ->Name = L"btQ";
            this->btQ->Size = System::Drawing::Size(45, 41);
            this->btQ->TabIndex = 16;
            this->btQ->Text = L"Q";
            this->btQ->UseVisualStyleBackColor = false;
            // 
            // btP
            // 
            this->btP->BackColor = System::Drawing::Color::Transparent;
            this->btP->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btP->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btP->Location = System::Drawing::Point(272, 122);
            this->btP->Name = L"btP";
            this->btP->Size = System::Drawing::Size(45, 41);
            this->btP->TabIndex = 15;
            this->btP->Text = L"P";
            this->btP->UseVisualStyleBackColor = false;
            // 
            // btO
            // 
            this->btO->BackColor = System::Drawing::Color::Transparent;
            this->btO->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btO->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btO->Location = System::Drawing::Point(221, 122);
            this->btO->Name = L"btO";
            this->btO->Size = System::Drawing::Size(45, 41);
            this->btO->TabIndex = 14;
            this->btO->Text = L"O";
            this->btO->UseVisualStyleBackColor = false;
            // 
            // btN
            // 
            this->btN->BackColor = System::Drawing::Color::Transparent;
            this->btN->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btN->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btN->Location = System::Drawing::Point(170, 122);
            this->btN->Name = L"btN";
            this->btN->Size = System::Drawing::Size(45, 41);
            this->btN->TabIndex = 13;
            this->btN->Text = L"N";
            this->btN->UseVisualStyleBackColor = false;
            // 
            // btM
            // 
            this->btM->BackColor = System::Drawing::Color::Transparent;
            this->btM->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btM->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btM->Location = System::Drawing::Point(119, 122);
            this->btM->Name = L"btM";
            this->btM->Size = System::Drawing::Size(45, 41);
            this->btM->TabIndex = 12;
            this->btM->Text = L"M";
            this->btM->UseVisualStyleBackColor = false;
            // 
            // btL
            // 
            this->btL->BackColor = System::Drawing::Color::Transparent;
            this->btL->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btL->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btL->Location = System::Drawing::Point(374, 75);
            this->btL->Name = L"btL";
            this->btL->Size = System::Drawing::Size(45, 41);
            this->btL->TabIndex = 11;
            this->btL->Text = L"L";
            this->btL->UseVisualStyleBackColor = false;
            // 
            // btK
            // 
            this->btK->BackColor = System::Drawing::Color::Transparent;
            this->btK->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btK->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btK->Location = System::Drawing::Point(323, 75);
            this->btK->Name = L"btK";
            this->btK->Size = System::Drawing::Size(45, 41);
            this->btK->TabIndex = 10;
            this->btK->Text = L"K";
            this->btK->UseVisualStyleBackColor = false;
            // 
            // btJ
            // 
            this->btJ->BackColor = System::Drawing::Color::Transparent;
            this->btJ->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btJ->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btJ->Location = System::Drawing::Point(272, 75);
            this->btJ->Name = L"btJ";
            this->btJ->Size = System::Drawing::Size(45, 41);
            this->btJ->TabIndex = 9;
            this->btJ->Text = L"J";
            this->btJ->UseVisualStyleBackColor = false;
            // 
            // btI
            // 
            this->btI->BackColor = System::Drawing::Color::Transparent;
            this->btI->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btI->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btI->Location = System::Drawing::Point(221, 75);
            this->btI->Name = L"btI";
            this->btI->Size = System::Drawing::Size(45, 41);
            this->btI->TabIndex = 8;
            this->btI->Text = L"I";
            this->btI->UseVisualStyleBackColor = false;
            // 
            // btH
            // 
            this->btH->BackColor = System::Drawing::Color::Transparent;
            this->btH->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btH->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btH->Location = System::Drawing::Point(170, 75);
            this->btH->Name = L"btH";
            this->btH->Size = System::Drawing::Size(45, 41);
            this->btH->TabIndex = 7;
            this->btH->Text = L"H";
            this->btH->UseVisualStyleBackColor = false;
            // 
            // btG
            // 
            this->btG->BackColor = System::Drawing::Color::Transparent;
            this->btG->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btG->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btG->Location = System::Drawing::Point(119, 75);
            this->btG->Name = L"btG";
            this->btG->Size = System::Drawing::Size(45, 41);
            this->btG->TabIndex = 6;
            this->btG->Text = L"G";
            this->btG->UseVisualStyleBackColor = false;
            // 
            // btF
            // 
            this->btF->BackColor = System::Drawing::Color::Transparent;
            this->btF->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btF->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btF->Location = System::Drawing::Point(374, 28);
            this->btF->Name = L"btF";
            this->btF->Size = System::Drawing::Size(45, 41);
            this->btF->TabIndex = 5;
            this->btF->Text = L"F";
            this->btF->UseVisualStyleBackColor = false;
            // 
            // btE
            // 
            this->btE->BackColor = System::Drawing::Color::Transparent;
            this->btE->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btE->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btE->Location = System::Drawing::Point(323, 28);
            this->btE->Name = L"btE";
            this->btE->Size = System::Drawing::Size(45, 41);
            this->btE->TabIndex = 4;
            this->btE->Text = L"E";
            this->btE->UseVisualStyleBackColor = false;
            // 
            // btD
            // 
            this->btD->BackColor = System::Drawing::Color::Transparent;
            this->btD->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btD->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btD->Location = System::Drawing::Point(272, 28);
            this->btD->Name = L"btD";
            this->btD->Size = System::Drawing::Size(45, 41);
            this->btD->TabIndex = 3;
            this->btD->Text = L"D";
            this->btD->UseVisualStyleBackColor = false;
            // 
            // btC
            // 
            this->btC->BackColor = System::Drawing::Color::Transparent;
            this->btC->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btC->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btC->Location = System::Drawing::Point(221, 28);
            this->btC->Name = L"btC";
            this->btC->Size = System::Drawing::Size(45, 41);
            this->btC->TabIndex = 2;
            this->btC->Text = L"C";
            this->btC->UseVisualStyleBackColor = false;
            // 
            // btB
            // 
            this->btB->BackColor = System::Drawing::Color::Transparent;
            this->btB->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btB->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btB->Location = System::Drawing::Point(170, 28);
            this->btB->Name = L"btB";
            this->btB->Size = System::Drawing::Size(45, 41);
            this->btB->TabIndex = 1;
            this->btB->Text = L"B";
            this->btB->UseVisualStyleBackColor = false;
            // 
            // btA
            // 
            this->btA->BackColor = System::Drawing::Color::Transparent;
            this->btA->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btA->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btA->Location = System::Drawing::Point(119, 28);
            this->btA->Name = L"btA";
            this->btA->Size = System::Drawing::Size(45, 41);
            this->btA->TabIndex = 0;
            this->btA->Text = L"A";
            this->btA->UseVisualStyleBackColor = false;
            // 
            // panelSpanzuratoare
            // 
            this->panelSpanzuratoare->Location = System::Drawing::Point(555, 82);
            this->panelSpanzuratoare->Name = L"panelSpanzuratoare";
            this->panelSpanzuratoare->Size = System::Drawing::Size(323, 324);
            this->panelSpanzuratoare->TabIndex = 4;
            // 
            // flpScor
            // 
            this->flpScor->BackColor = System::Drawing::Color::Transparent;
            this->flpScor->Controls->Add(this->panel28);
            this->flpScor->Controls->Add(this->panelAdaugare);
            this->flpScor->Controls->Add(this->panelTabel);
            this->flpScor->Location = System::Drawing::Point(0, 10);
            this->flpScor->Name = L"flpScor";
            this->flpScor->Size = System::Drawing::Size(888, 406);
            this->flpScor->TabIndex = 4;
            // 
            // panel28
            // 
            this->panel28->Controls->Add(this->lbTitluScor);
            this->panel28->Controls->Add(this->panel29);
            this->panel28->Location = System::Drawing::Point(3, 3);
            this->panel28->Name = L"panel28";
            this->panel28->Size = System::Drawing::Size(884, 73);
            this->panel28->TabIndex = 3;
            // 
            // lbTitluScor
            // 
            this->lbTitluScor->AutoSize = true;
            this->lbTitluScor->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbTitluScor->Location = System::Drawing::Point(493, 5);
            this->lbTitluScor->Name = L"lbTitluScor";
            this->lbTitluScor->Size = System::Drawing::Size(122, 60);
            this->lbTitluScor->TabIndex = 8;
            this->lbTitluScor->Text = L"Scor";
            // 
            // panel29
            // 
            this->panel29->Controls->Add(this->panel30);
            this->panel29->Location = System::Drawing::Point(38, 3);
            this->panel29->Name = L"panel29";
            this->panel29->Size = System::Drawing::Size(74, 62);
            this->panel29->TabIndex = 7;
            // 
            // panel30
            // 
            this->panel30->Controls->Add(this->btHome2);
            this->panel30->Location = System::Drawing::Point(19, 0);
            this->panel30->Name = L"panel30";
            this->panel30->Size = System::Drawing::Size(130, 100);
            this->panel30->TabIndex = 3;
            // 
            // btHome2
            // 
            this->btHome2->BackColor = System::Drawing::Color::Transparent;
            this->btHome2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btHome2->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->btHome2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btHome2.Image")));
            this->btHome2->Location = System::Drawing::Point(-36, -20);
            this->btHome2->Name = L"btHome2";
            this->btHome2->Size = System::Drawing::Size(107, 97);
            this->btHome2->TabIndex = 0;
            this->btHome2->UseVisualStyleBackColor = false;
            this->btHome2->Click += gcnew System::EventHandler(this, &MainForm::BtHome2_Click);
            // 
            // panelAdaugare
            // 
            this->panelAdaugare->Controls->Add(this->txtNume);
            this->panelAdaugare->Controls->Add(this->btAdauga);
            this->panelAdaugare->Controls->Add(this->label3);
            this->panelAdaugare->Controls->Add(this->labelScorul);
            this->panelAdaugare->Controls->Add(this->label4);
            this->panelAdaugare->Location = System::Drawing::Point(3, 82);
            this->panelAdaugare->Name = L"panelAdaugare";
            this->panelAdaugare->Size = System::Drawing::Size(163, 199);
            this->panelAdaugare->TabIndex = 3;
            // 
            // txtNume
            // 
            this->txtNume->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtNume->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtNume->Location = System::Drawing::Point(24, 133);
            this->txtNume->Name = L"txtNume";
            this->txtNume->Size = System::Drawing::Size(117, 14);
            this->txtNume->TabIndex = 12;
            this->txtNume->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // btAdauga
            // 
            this->btAdauga->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btAdauga->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btAdauga->Location = System::Drawing::Point(38, 166);
            this->btAdauga->Name = L"btAdauga";
            this->btAdauga->Size = System::Drawing::Size(86, 30);
            this->btAdauga->TabIndex = 0;
            this->btAdauga->Text = L"Adauga";
            this->btAdauga->UseVisualStyleBackColor = true;
            this->btAdauga->Click += gcnew System::EventHandler(this, &MainForm::btAdauga_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(51, 97);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(56, 19);
            this->label3->TabIndex = 11;
            this->label3->Text = L"Nume:";
            // 
            // labelScorul
            // 
            this->labelScorul->AutoSize = true;
            this->labelScorul->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->labelScorul->Location = System::Drawing::Point(60, 59);
            this->labelScorul->Name = L"labelScorul";
            this->labelScorul->Size = System::Drawing::Size(64, 24);
            this->labelScorul->TabIndex = 10;
            this->labelScorul->Text = L"label3";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Bradley Hand ITC", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(18, 27);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(123, 19);
            this->label4->TabIndex = 10;
            this->label4->Text = L"Scorul tau este:";
            // 
            // panelTabel
            // 
            this->panelTabel->Controls->Add(this->dgvScor);
            this->panelTabel->Location = System::Drawing::Point(172, 82);
            this->panelTabel->Name = L"panelTabel";
            this->panelTabel->Size = System::Drawing::Size(697, 324);
            this->panelTabel->TabIndex = 4;
            // 
            // dgvScor
            // 
            this->dgvScor->AllowUserToAddRows = false;
            this->dgvScor->AllowUserToDeleteRows = false;
            this->dgvScor->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvScor->Location = System::Drawing::Point(204, 4);
            this->dgvScor->Name = L"dgvScor";
            this->dgvScor->ReadOnly = true;
            this->dgvScor->Size = System::Drawing::Size(342, 206);
            this->dgvScor->TabIndex = 0;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(893, 423);
            this->Controls->Add(this->flpScor);
            this->Controls->Add(this->flpJoc);
            this->Controls->Add(this->flpDomeniu);
            this->Controls->Add(this->flpMeniu);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MainForm";
            this->Text = L"Spanzuratoarea";
            this->flpMeniu->ResumeLayout(false);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->panel3->ResumeLayout(false);
            this->panel4->ResumeLayout(false);
            this->panel5->ResumeLayout(false);
            this->panel6->ResumeLayout(false);
            this->panel7->ResumeLayout(false);
            this->flpDomeniu->ResumeLayout(false);
            this->panel8->ResumeLayout(false);
            this->panel8->PerformLayout();
            this->panel21->ResumeLayout(false);
            this->panel22->ResumeLayout(false);
            this->panel9->ResumeLayout(false);
            this->panel10->ResumeLayout(false);
            this->panel11->ResumeLayout(false);
            this->panel12->ResumeLayout(false);
            this->panel13->ResumeLayout(false);
            this->panel14->ResumeLayout(false);
            this->panel15->ResumeLayout(false);
            this->panel16->ResumeLayout(false);
            this->panel17->ResumeLayout(false);
            this->panel18->ResumeLayout(false);
            this->panel19->ResumeLayout(false);
            this->panel20->ResumeLayout(false);
            this->flpJoc->ResumeLayout(false);
            this->panelCuvant->ResumeLayout(false);
            this->panelCuvant->PerformLayout();
            this->panel23->ResumeLayout(false);
            this->panel24->ResumeLayout(false);
            this->panelScor->ResumeLayout(false);
            this->panelScor->PerformLayout();
            this->panel26->ResumeLayout(false);
            this->panel25->ResumeLayout(false);
            this->panel27->ResumeLayout(false);
            this->flpScor->ResumeLayout(false);
            this->panel28->ResumeLayout(false);
            this->panel28->PerformLayout();
            this->panel29->ResumeLayout(false);
            this->panel30->ResumeLayout(false);
            this->panelAdaugare->ResumeLayout(false);
            this->panelAdaugare->PerformLayout();
            this->panelTabel->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvScor))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

        void InitializeGame(void)
        {
            greseli = 0;
            //scor = 0;
            //streak = 0;
            hintFolosite = false;
            cuvantCurent = "";
            cuvantAfisat = "";
        }

        void MainForm::SelecteazaDomeniu(System::Object^ sender, System::EventArgs^ e)
        {
            Button^ btn = safe_cast<Button^>(sender);
            if (btn->Name == "btAnimale") {
                cuvinteCurente = cuvinteAnimale;
                domeniuSelectat = "Animale";
            }
            else if (btn->Name == "btCulori") {
                cuvinteCurente = cuvinteCulori;
                domeniuSelectat = "Culori";
            }
            else if (btn->Name == "btMancare") {
                cuvinteCurente = cuvinteMancare;
                domeniuSelectat = "Mancare";
            }
            else if (btn->Name == "btCorp") {
                cuvinteCurente = cuvinteCorp;
                domeniuSelectat = "Corpul uman";
            }
            else if (btn->Name == "btMobila") {
                cuvinteCurente = cuvinteMobila;
                domeniuSelectat = "Mobila";
            }
            else if (btn->Name == "btMunca") {
                cuvinteCurente = cuvinteMunca;
                domeniuSelectat = "Locuri de Munca";
            }

            cuvantIndex = 0;
            InitializeazaCuvant();
            flpMeniu->Visible = false;
            flpDomeniu->Visible = false;
            flpJoc->Visible = true;
        }

        void InitializeazaCuvant()
        {
            if (cuvantIndex < cuvinteCurente->Length)
            {
                cuvantCurent = cuvinteCurente[cuvantIndex++];
                cuvantAfisat = cuvantCurent[0] + gcnew String('_', cuvantCurent->Length - 2) + cuvantCurent[cuvantCurent->Length - 1];
                greseli = 0; // Resetarea greșelilor
                AfiseazaCuvant();
                panelSpanzuratoare->Invalidate(); // Reafișarea spânzurătorii

                // Reactivarea butoanelor alfabetice
                for each (Control ^ ctrl in panel26->Controls)
                {
                    Button^ btn = dynamic_cast<Button^>(ctrl);
                    if (btn)
                    {
                        btn->Enabled = true;
                    }
                }

                // Resetarea și reactivarea butonului de hint
                hintFolosite = false;
                btHint->Enabled = true;
            }
            else
            {
                // Toate cuvintele au fost ghicite
                //MessageBox::Show("Felicitări! Ai ghicit toate cuvintele din acest domeniu.\nScorul tău este: " + scor.ToString());
                //ResetGameVariables();
                flpScor->Visible = true;
                flpMeniu->Visible = false;
                flpDomeniu->Visible = false;
                flpJoc->Visible = false;
                txtNume->Enabled = true;
                btAdauga->Enabled = true;
                AfiseazaScoruri();
            }
        }

        void ResetGameVariables()
        {
            cuvantIndex = 0;
            cuvinteGhicite = 0;
            cuvinteNeghicite = 0;
            scor = 0;
            streak = 0;
            hintFolosite = false;
            ActualizeazaScor();
        }

        void AfiseazaCuvant()
        {
            System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
            for (int i = 0; i < cuvantAfisat->Length; ++i)
            {
                sb->Append(cuvantAfisat[i]);
                if (i < cuvantAfisat->Length - 1)
                {
                    sb->Append(" ");
                }
            }
            labelCuvant->Text = sb->ToString();
        }

        void ActualizeazaScor()
        {
            // Actualizează textul labelScor
            labelScor->Text = String::Format("({0}/{1})\nScor: {2}\nStreak: {3}", cuvinteGhicite, cuvinteNeghicite, scor, streak);
            labelScorul->Text = scor.ToString();
        }

        void VerificaLitera(System::Object^ sender, System::EventArgs^ e)
        {
            Button^ btn = safe_cast<Button^>(sender);
            wchar_t litera = btn->Text[0];
            bool gasit = false;
            for (int i = 1; i < cuvantCurent->Length - 1; ++i)
            {
                if (cuvantCurent[i] == litera)
                {
                    cuvantAfisat = cuvantAfisat->Remove(i, 1)->Insert(i, litera.ToString());
                    gasit = true;
                }
            }
            if (!gasit)
            {
                greseli++;
            }
            btn->Enabled = false;
            AfiseazaCuvant();
            panelSpanzuratoare->Invalidate(); // Actualizează spânzurătoarea după fiecare greșeală

            // Verificăm dacă întregul cuvânt a fost ghicit
            if (cuvantAfisat->IndexOf('_') == -1)
            {
                cuvinteGhicite++;
                scor += 10 * (streak + 1); // Scorul se dublează, triplează etc. în funcție de streak
                streak++;
                InitializeazaCuvant(); // Inițializăm un nou cuvânt
            }
            else if (greseli >= 6) // Presupunem că jucătorul are 6 încercări
            {
                cuvinteNeghicite++;
                streak = 0; // Resetăm streak-ul la 0 dacă greșim
                InitializeazaCuvant(); // Inițializăm un nou cuvânt
            }

            ActualizeazaScor();
        }


        private:
            void panelSpanzuratoare_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
            {
                Graphics^ g = e->Graphics;
                Pen^ pen = gcnew Pen(Color::Black, 10); // Grosimea pen-ului setată la 10

                // Ajustează coordonatele pentru a muta desenul mai sus și mai la stânga
                int offsetX = -50; // Ajustează această valoare pentru a muta desenul la stânga
                int offsetY = -20; // Ajustează această valoare pentru a muta desenul în sus

                // Desenarea spânzurătorii constante
                g->DrawLine(pen, Point(50 + offsetX, 300 + offsetY), Point(250 + offsetX, 300 + offsetY)); // Baza
                g->DrawLine(pen, Point(150 + offsetX, 50 + offsetY), Point(150 + offsetX, 300 + offsetY)); // Stâlp
                g->DrawLine(pen, Point(150 + offsetX, 50 + offsetY), Point(250 + offsetX, 50 + offsetY)); // Bara orizontală
                g->DrawLine(pen, Point(250 + offsetX, 50 + offsetY), Point(250 + offsetX, 100 + offsetY)); // Frânghia

                // Desenarea spânzuratului în funcție de numărul de greșeli
                if (greseli > 0) // Cap
                    g->DrawEllipse(pen, 235 + offsetX, 100 + offsetY, 30, 30);
                if (greseli > 1) // Corp
                    g->DrawLine(pen, Point(250 + offsetX, 130 + offsetY), Point(250 + offsetX, 200 + offsetY));
                if (greseli > 2) // Picior stâng
                    g->DrawLine(pen, Point(250 + offsetX, 200 + offsetY), Point(230 + offsetX, 250 + offsetY));
                if (greseli > 3) // Picior drept
                    g->DrawLine(pen, Point(250 + offsetX, 200 + offsetY), Point(270 + offsetX, 250 + offsetY));
                if (greseli > 4) // Braț stâng
                    g->DrawLine(pen, Point(250 + offsetX, 150 + offsetY), Point(230 + offsetX, 180 + offsetY));
                if (greseli > 5) // Braț drept
                    g->DrawLine(pen, Point(250 + offsetX, 150 + offsetY), Point(270 + offsetX, 180 + offsetY));
            }


        

        void ResetareJoc()
        {
            greseli = 0;
            hintFolosite = false;
            InitializeazaCuvant();
            for each (Control ^ ctrl in panel26->Controls)
            {
                Button^ btn = dynamic_cast<Button^>(ctrl);
                if (btn)
                {
                    btn->Enabled = true;
                }
            }
            btHint->Enabled = true;
        }

        void Hint(System::Object^ sender, System::EventArgs^ e)
        {
            array<int>^ pozitii = gcnew array<int>(cuvantCurent->Length - 2);
            int pozitieIndex = 0;
            for (int i = 1; i < cuvantCurent->Length - 1; ++i)
            {
                if (cuvantAfisat[i] == '_')
                {
                    pozitii[pozitieIndex++] = i;
                }
            }
            if (pozitieIndex > 0)
            {
                srand((unsigned int)time(0));
                int idx = pozitii[rand() % pozitieIndex];
                wchar_t litera = cuvantCurent[idx];

                // Inlocuieste toate aparitiile literei in cuvantAfisat
                for (int i = 0; i < cuvantCurent->Length; ++i)
                {
                    if (cuvantCurent[i] == litera)
                    {
                        cuvantAfisat = cuvantAfisat->Remove(i, 1)->Insert(i, cuvantCurent[i].ToString());
                    }
                }

                // Dezactiveaza toate butoanele corespunzatoare literei
                for each (Control ^ ctrl in panel26->Controls)
                {
                    Button^ btn = dynamic_cast<Button^>(ctrl);
                    if (btn && btn->Text[0] == litera)
                    {
                        btn->Enabled = false;
                    }
                }

                AfiseazaCuvant();
                hintFolosite = true;
                btHint->Enabled = false;
            }
        }

        void BtHome_Click(System::Object^ sender, System::EventArgs^ e)
        {
            ResetGameVariables();
            flpMeniu->Visible = true;
            flpDomeniu->Visible = false;
            flpJoc->Visible = false;
            ResetareJoc();
        }

        void CreareFisierScoruri()
        {
            std::ifstream infile("scoruri.txt");
            if (!infile.good())
            {
                std::ofstream outfile("scoruri.txt");
                outfile << "Nume,Domeniu,Scor\n"; // Header pentru fișier
                outfile.close();
            }
        }

        static bool comparaScoruri(const std::tuple<std::string, std::string, int>& a, const std::tuple<std::string, std::string, int>& b) {
            return std::get<2>(a) > std::get<2>(b);
        }


        void MainForm::btAdauga_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                // Convertește scorul la std::string
                std::string scoreStdString = std::to_string(scor);

                // Verifică dacă scorul este gol și setează o valoare implicită dacă este necesar
                if (scoreStdString.empty()) {
                    scoreStdString = "0"; // Sau orice valoare implicită
                }

                // Verifică dacă un domeniu a fost selectat
                if (String::IsNullOrEmpty(domeniuSelectat)) {
                    Console::WriteLine("Niciun domeniu nu a fost selectat.");
                    return;
                }

                // Obține numele jucătorului
                System::String^ playerName = txtNume->Text;

                // Verifică dacă numele jucătorului este gol
                if (String::IsNullOrEmpty(playerName)) {
                    Console::WriteLine("Numele jucatorului nu poate fi gol.");
                    return;
                }

                // Convertește std::string la System::String^
                System::String^ scoreString = msclr::interop::marshal_as<System::String^>(scoreStdString);

                // Verifică dacă conversia a avut succes
                if (scoreString == nullptr) {
                    Console::WriteLine("scoreString is null");
                }
                else {
                    Console::WriteLine("scoreString: " + scoreString);
                }

                // Creează linia de text care va fi adăugată în fișier și în dgvScor
                System::String^ line = playerName + ", " + domeniuSelectat + ", " + scoreString;

                // Adaugă linia în fișierul text
                System::IO::File::AppendAllText("scoruri.txt", line + Environment::NewLine);

                // Adaugă linia în dgvScor
                dgvScor->Rows->Add(gcnew array<System::Object^> { playerName, domeniuSelectat, scoreString });

            }
            catch (System::Exception^ ex) {
                // Gestionează excepțiile
                Console::WriteLine("A aparut o eroare: " + ex->Message);
            }
            txtNume->Enabled = false;
            btAdauga->Enabled = false;
        }


        void MainForm::AfiseazaScoruri() {
            try {
                // Curăță rândurile existente din dgvScor
                dgvScor->Rows->Clear();

                // Curăță coloanele existente și adaugă titlurile coloanelor
                dgvScor->Columns->Clear();
                dgvScor->Columns->Add("Nume", "Nume");
                dgvScor->Columns->Add("Domeniu", "Domeniu");
                dgvScor->Columns->Add("Scor", "Scor");

                // Citește toate liniile din fișierul text
                array<System::String^>^ lines = System::IO::File::ReadAllLines("scoruri.txt");

                // Parcurge fiecare linie și adaug-o în dgvScor
                for each (System::String ^ line in lines) {
                    // Împarte linia în componente (presupunând că sunt separate prin virgulă)
                    array<System::String^>^ parts = line->Split(',');

                    // Verifică dacă linia are exact 3 componente (nume, domeniu, scor)
                    if (parts->Length == 3) {
                        System::String^ playerName = parts[0]->Trim();
                        System::String^ selectedDomain = parts[1]->Trim();
                        System::String^ scoreString = parts[2]->Trim();

                        // Adaugă linia în dgvScor
                        dgvScor->Rows->Add(gcnew array<System::Object^> { playerName, selectedDomain, scoreString });
                    }
                }
            }
            catch (System::Exception^ ex) {
                // Gestionează excepțiile
                Console::WriteLine("A aparut o eroare la citirea scorurilor: " + ex->Message);
            }
        }

        void BtHome2_Click(System::Object^ sender, System::EventArgs^ e)
        {
            ResetGameVariables();
            flpMeniu->Visible = true;
            flpDomeniu->Visible = false;
            flpJoc->Visible = false;
            flpScor->Visible = false;
            //ResetareJoc();
        }

           
    private: System::Void btJoaca_Click(System::Object^ sender, System::EventArgs^ e) {
        flpMeniu->Visible = false;
        flpDomeniu->Visible = true;
        flpJoc->Visible = false;
    }
    private: System::Void btScor_Click(System::Object^ sender, System::EventArgs^ e) {
        flpMeniu->Visible = false;
        flpDomeniu->Visible = false;
        flpJoc->Visible = false;
        flpScor->Visible = true;
        btAdauga->Enabled = false;
        txtNume->Enabled = false;
        AfiseazaScoruri();
    }
    private: System::Void btIesire_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
    private: System::Void btBack_Click(System::Object^ sender, System::EventArgs^ e) {
        flpMeniu->Visible = true;
        flpDomeniu->Visible = false;
        flpJoc->Visible = false;
    }
    };
}