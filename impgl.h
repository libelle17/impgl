#define DPROG "impgl"
// fuer verschiedene Sprachen //α
enum T_      
{
	T_virtVorgbAllg,
	T_pvirtVorgbSpeziell,
	T_virtMusterVorgb,
	T_pvirtvorrueckfragen,
	T_virtrueckfragen,
	T_virtpruefweiteres,
	T_virtmacherkl_Tx_lgn,
	T_Fehler_beim_Pruefen_von,
	T_st_k,
	T_stop_l,
	T_DPROG_anhalten,
	T_anhalten,
	T_Cron_Aufruf_von,
	T_gestoppt,
	T_n_k,
	T_dszahl_l,
	T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,
	T_Datenbank_nicht_initialisierbar_breche_ab,
	T_Fuege_ein, //ω
	T_Fehler_beim_Oeffnen_der_Datenbank,
	T_eindeutige_Identifikation,
	T_PZN_aus_gelber_Liste,
	T_Fehler_beim_Erstellen_von,
	T_Datensaetze_verarbeitet,
	T_MAX //α
}; // enum T_ //ω
//α
class hhcl:public dhcl
{
	private: 
		uchar anhl=0;    // <DPROG> anhalten
		string dszahl="30"; // Datensatzzahl fuer Tabellenausgaben
		//ω
	protected: //α
		string p1;
		int p2;
		string p3;
		uchar oblista=0;
		long listz=30; //ω
	public: //α //ω
	private: //α //ω
		void virttesterg(); //α
		void virtlieskonfein();
		void virtautokonfschreib();
		void anhalten(); //ω
	protected: //α
		// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
		void virtVorgbAllg();
		void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
			;
		void virtinitopt(); // (programm-)spezifische Optionen
		void pvirtmacherkl();
		void virtMusterVorgb();
		void pvirtvorzaehler();
		void virtzeigversion(const string& ltiffv=nix);
		void pvirtvorrueckfragen();
		void virtrueckfragen();
		void pvirtvorpruefggfmehrfach();
		void virtpruefweiteres();
		void virtzeigueberschrift();
		void pvirtfuehraus();
		void virtschlussanzeige();
		void zeigdienste(); //ω
		long import_firebird(const string& fbdb,const string& fbtb,const string& mydb,const string *mytbp=0,const string& comment=nix);
		void wandle();
	public: //α
		hhcl(const int argc, const char *const *const argv);
		~hhcl();
		friend class fsfcl;
}; // class hhcl //ω
