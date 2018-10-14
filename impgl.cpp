// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
const double& versnr= //α
#include "versdt"
;
#include "kons.h"
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "impgl.h"
// fuer verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]={
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_pvirtVorgbSpeziell
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	// T_virtpruefweiteres
	{"virtpruefweiteres()","virtcheckmore()"},
	// T_virtmacherkl_Tx_lgn
	{"pvirtmacherkl, Tx.lgn: ","pvirtmakeexpl, Tx.lgn: "},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_st_k
	{"st","st"},
	// T_stop_l
	{"stop","stop"},
	// T_DPROG_anhalten
	{DPROG " anhalten","stop " DPROG},
	// T_anhalten
	{"anhalten()","stop()"},
	// T_Cron_Aufruf_von
	{"Cron-Aufruf von '","cron call of '"},
	// T_gestoppt
	{"' gestoppt.","' stopped."},
	// T_n_k
	{"n","n"},
	// T_dszahl_l
	{"dszahl","reccount"},
	// T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt
	{"Zahl der aufzulistenden Datensaetze = <zahl> statt","No. of listed entries = <no> instead of"},
	// T_Datenbank_nicht_initialisierbar_breche_ab
	{"Datenbank nicht initialisierbar, breche ab","database init failed, stopping"},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	// T_Fehler_beim_Oeffnen_der_Datenbank
	{" Fehler beim Oeffnen der Datenbank "," Error while opening database "},
	// T_eindeutige_Identifikation
	{"eindeutige Identifikation","distinct identification"},
	// T_PZN_aus_gelber_Liste
	{"PZN aus gelber Liste","pharma central number from yellow list"},
	// T_Fehler_beim_Erstellen_von
	{"Fehler beim Erstellen von ","Error while creating "},
	// T_Datensaetze_verarbeitet
	{" Datensaetze verarbeitet"," data sets processed"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char sep = 9; // geht auch: "[[:blank:]]"
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;
pidvec pidw;
const unsigned ktage=1; // kurzes Intervall fuer Faxtabellenkorrektur, 1 Tag
const unsigned mtage=30; // mittleres Intervall fuer Faxtabellenkorrektur, 1 Monat
const unsigned ltage=73000; // langes Intervall fuer Faxtabellenkorrektur, 200 Jahre

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG,/*mitcron*/1) //α
{
 // mitcron=0; //ω
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω
//α
// wird aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	hLog(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
	dhcl::virtVorgbAllg(); //α
} // void hhcl::virtVorgbAllg

// wird aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	hLog(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz);
	virtMusterVorgb(); //ω
	dhcl::pvirtVorgbSpeziell(); //α
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	opn<<new optcl(/*pname*/"",/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1); //α //ω
	opn<<new optcl(/*pname*/"",/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1); //α //ω
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	hLog(violetts+Tx[T_virtmacherkl_Tx_lgn]+schwarz+ltoan(Tx.lgn));
//	erkl<<violett<<DPROG<<blau<<Txk[T_tut_dieses_und_jenes]<<schwarz; //ω 
} // void hhcl::pvirtmacherkl //α
//ω
//α
// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// wird aufgerufen in lauf
void hhcl::pvirtvorzaehler()
{ //ω
} // void hhcl::virtvorzaehler() //α
//ω
// wird aufgerufen in lauf //α
void hhcl::virtzeigversion(const string& ltiffv/*=nix*/)
{
	dhcl::virtzeigversion(ltiffv);  //ω
} // void hhcl::virtzeigversion //α
//ω
//α
// wird aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	hLog(violetts+Tx[T_pvirtvorrueckfragen]+schwarz); //ω
} // void hhcl::pvirtvorrueckfragen //α


// wird aufgerufen in lauf
void hhcl::virtrueckfragen()
{
	hLog(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) { //ω
	} // if (rzf) //α
	dhcl::virtrueckfragen();
	//// opn.oausgeb(rot);
} // void hhcl::virtrueckfragen()
//ω
//α
// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{
	fLog(violetts+Tx[T_virtpruefweiteres]+schwarz,obverb,oblog); //ω
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab])); //α //ω
	if (initDB()) {
		exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));
	}
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ //ω
	// hier ggf. noch etwas an 'uebers' anhaengen //α
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift
//ω
//α
// Parameter -st / --stop
// wird aufgerufen in: main
void hhcl::anhalten()
{
	hLog(violetts+Tx[T_anhalten]+schwarz);
	// crontab
	/*
	setztmpcron();
	for(int iru=0;iru<1;iru++) {
		const string befehl=
			"bash -c 'grep \""+saufr[iru]+"\" -q <(crontab -l)&&{ crontab -l|sed \"/"+zsaufr[iru]+"/d\">"+tmpcron+";crontab "+tmpcron+";};:'";
		systemrueck(befehl,obverb,oblog,*//*rueck=*//*0,*//*obsudc=*//*1);
	} // 	for(int iru=0;iru<2;iru++)
  */
	pruefcron("0"); // soll vor Log(Tx[T_Verwende ... stehen
	fLog(blaus+Tx[T_Cron_Aufruf_von]+schwarz+mpfad+blau+Tx[T_gestoppt]+schwarz,1,oblog); //ω
} // void hhcl::anhalten() //α
//ω
//α
void hhcl::pvirtvorpruefggfmehrfach()
{
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));  //ω
} // void hhcl::pvirtvorpruefggfmehrfach //α
//ω
const string befpfad{"/opt/firebird/bin/"},
						 isql{befpfad+"isql"}; // isql-fb
long hhcl::import_firebird(const string& fbdb,const string& fbtb,const string& mydb,const string *mytbp/*=0*/,const string& comment/*=nix*/)
{
	const char tz[4]{29,30,31,0}; // sehr unwahrscheinliche Zeichenfolge
	const size_t aktc{0};
	const string pznn{"PCK_PZN"};
	if (!mytbp) mytbp=&fbtb;
	svec csets;
	csets<<"latin1";
	csets<<"utf8";
	string sql= "SELECT iif(r.rdb$field_position is null,0,r.rdb$field_position)||';'||iif(r.rdb$field_name is null,'',TRIM(r.RDB$FIELD_NAME))||';'||iif(r.rdb$null_flag is null,'',trim(r.rdb$null_flag))||';'||iif(f.rdb$field_length is null,0,trim(f.RDB$FIELD_LENGTH))||';'||iif(f.rdb$field_precision is null,0,trim(f.RDB$FIELD_PRECISION))||';'||iif(f.rdb$field_scale is null,'',trim(f.RDB$FIELD_SCALE))||';'||iif(f.rdb$field_type is null,'',trim(CASE f.RDB$FIELD_TYPE WHEN 261 THEN'BLOB'WHEN 14 THEN'CHAR'WHEN 40 THEN'CSTRING'WHEN 11 THEN'D_FLOAT'WHEN 27 THEN'DOUBLE'WHEN 10 THEN'FLOAT'WHEN 16 THEN'INT64'WHEN 8 THEN'INTEGER'WHEN 9 THEN'QUAD'WHEN 7 THEN'SMALLINT'WHEN 12 THEN'DATE'WHEN 13 THEN'TIME'WHEN 35 THEN'TIMESTAMP'WHEN 37 THEN'VARCHAR'ELSE'UNKNOWN'END))||';'||iif(f.rdb$field_sub_type is null,'',trim(f.RDB$FIELD_SUB_TYPE))||';'||iif(coll.rdb$collation_name is null,'',trim(coll.rdb$collation_name))||';'||iif(cset.rdb$character_set_name is \
null,'',trim(cset.RDB$CHARACTER_SET_NAME))||';' FROM RDB$RELATION_FIELDS r LEFT JOIN RDB$FIELDS f ON r.RDB$FIELD_SOURCE = f.RDB$FIELD_NAME LEFT JOIN RDB$COLLATIONS coll ON f.RDB$COLLATION_ID = coll.RDB$COLLATION_ID LEFT JOIN RDB$CHARACTER_SETS cset ON f.RDB$CHARACTER_SET_ID = cset.RDB$CHARACTER_SET_ID WHERE r.RDB$RELATION_NAME='"+fbtb+"' ORDER BY r.RDB$FIELD_POSITION;";
	if (My->fehnr) {
		fLog(rots+ltoan(My->fehnr)+schwarz+Tx[T_Fehler_beim_Oeffnen_der_Datenbank]+mydb,obverb,oblog);
		return -29;
	} // 	if (My->fehnr)
	servc firebird("firebird","firebird");
	firebird.restart(obverb-1,oblog);
	// Script für Kopf,für Daten, Kopfdaten,Tabellendaten
	const string scriptendg{".script"},datendg{".dat"},
				header{"_hd"},daten{"_dt"},
				fbscr[2]={fbtb+header+scriptendg,fbtb+daten+scriptendg}, // /tmp/... GL_PCK_hd.script, GL_PCK_dt.script
				fbdat[2]={fbtb+header+datendg,fbtb+daten+datendg};       // /tmp/... GL_PCK_hd.dat, GL_PCK_dt.dat
	size_t fzl=0,dszahl=0; // Feldzahl,Datensatzzahl
	Feld *fdp;
	for(int ru=0;ru<2;ru++) {
		mdatei ga(fbscr[ru],ios::out);
		if (ga.is_open()) {
			ga<<"connect "<<fbdb<<";"<<endl; 
			ga<<"set heading off;"<<endl;
			ga<<"output "<<fbdat[ru]<<";"<<endl;
			ga<<sql<<endl;
			// in Runde 0 s.o., in Runde 1 s.u.
			sql.clear();
			ga.close();
			tuloeschen(fbdat[ru]);
			// schreibt durch Aufruf des Scripts fbdat[ru] fertig
			systemrueck(isql+" -u sysdba -p masterke -q -i "+fbscr[ru],obverb?obverb:1,oblog);
			if (!ru) {
				mdatei gl0(fbdat[ru],ios::in|ios::binary);
				if (gl0.is_open()) {
					string zeile;
					while (getline(gl0,zeile)) fzl++;
					gl0.close();
				} // 	if (gl0.is_open())
				if (fzl>1) { // 1. und letzte Zeile leer, dafür kommt noch ID dazu
					fzl-=1;
					mdatei gl(fbdat[0],ios::in|ios::binary);
					if (gl.is_open()) {
					// 1. mache Tabelle aus fbdat[0]
						size_t i=0;
						fdp=new Feld[fzl]; // erste und letzte Zeile leer
						memcpy(&fdp[0],new Feld("ID","INT","10","",Tx[T_eindeutige_Identifikation],1,1),sizeof *fdp);
						string zeile;
						while (getline(gl,zeile)) {
							if (i && i<fzl) {
								svec zfld;
								aufSplit(&zfld,zeile,';');
								////					if (obverb) for(size_t j=0;j<zfld.size();j++) caus<<blau<<i<<" "<<violett<<j<<" "<<schwarz<<zfld[j]<<endl;
								Feld *nfld;
								if (zfld.size()>6) {
									nfld=new Feld(zfld[1],zfld[6],zfld[3],zfld[4],"",0,0,0);
								} else {
									nfld= new Feld(ltoan(i));
								} // 				if (zfld.size()>6)
								memcpy(&fdp[i],nfld,sizeof *fdp);
							} // 							if (i && i<fzl)
							++i;
						} // 			while (getline(gl,zeile))
						Feld if0[]={Feld(pznn)}; Index i0(pznn,if0,sizeof if0/sizeof* if0); // PCK_PZN
						Feld if1[]={Feld("DISPLAYNAME")}; Index i1("DISPLAYNAME",if1,sizeof if1/sizeof* if1);
						Feld if2[]={Feld("PCK_REZEPTINFO")}; Index i2("PCK_REZEPTINFO",if2,sizeof if2/sizeof* if2);
						Index indices[]{i0,i1,i2};
						Tabelle taa(My,*mytbp,fdp,fzl,indices,sizeof indices/sizeof *indices,0,0,comment,"InnoDB","utf8","utf8_general_ci","DYNAMIC");
						////			if (obverb) for(size_t i=0;i<fzl;i++) caus<<blau<<i<<" '"<<schwarz<<fdp[i].name<<"' '"<<fdp[i].comment<<"'"<<endl;
						if (taa.prueftab(obverb)) {
							fLog(Tx[T_Fehler_beim_Erstellen_von]+*mytbp,1,1);
							return 0;
						} // 				if (My->prueftab(&taa,obverb))
						// RS trunc(My,("truncate "+*mytbp).c_str());
						// 2. mache SQL-Befehl für fbscr[1] aus fbdat[0]
						sql="SELECT "; // first 10
						for(size_t i=1;i<fzl;i++) {
							sql+="IIF("+fdp[i].name+" IS NULL,'',TRIM("+fdp[i].name+"))||'"+tz+"'";
							if (i<fzl-1) {
								sql+="||";
							} // 							if (i<fzl-1)
						} // 						for(size_t i=1;i<fzl;i++)
						sql+=" FROM "+fbtb+";";
					} // if (gl.is_open())
				} else {
					fLog("Feldzahl in "+fbdat[0]+" zu gering mit: "+ltoan(fzl),1,oblog);
				} // if (fzl>1)

			} else { // !ru else
				mdatei da(fbdat[ru],ios::in|ios::binary);
				if (da.is_open()) {
					string zeile;
					uchar anfangen=1;
					RS rins(My,*mytbp); // muss fuer sammeln vor while stehen
					while (getline(da,zeile)) {
					  dszahl++;
						if (!(dszahl % 10) || obverb)
							fLog(gruens+ltoan(dszahl)+blau+Tx[T_Datensaetze_verarbeitet],obverb?1:-1,0);
						svec eig;
						if (!zeile.empty()) aufSplit(&eig,zeile,(char*)tz);
						if (eig.size()<fzl) continue;
						string loesche{"DELETE FROM `"+*mytbp+"` WHERE "+pznn+"='"};
						uchar obloe{0};
						vector<instyp> einf;
						for(size_t j=0;j<eig.size()-1;j++) { // da das Trennzeichen nochmal ganz am Schluss
							if (eig[j].empty()) {
								eig[j]=fdp[j+1].defa;
							} // 									if (eig[j].empty())
							if (fdp[j+1].name==pznn) {loesche+=eig[j];loesche+="'";obloe=1;}
							einf.push_back(/*2*/instyp(My->DBS,fdp[j+1].name.c_str(),&eig[j]));
						} // 				for(size_t j=0;j<tok[0].size();j++)
						if (obloe)
							RS rsloe(My,loesche,aktc,ZDB);
						rins.tbins(&einf,aktc,0,ZDB?ZDB:obverb?obverb:-2,0,0,svec(),0,&csets);
//						caus<<".";
						anfangen=0;
					} // 					while (1)
					if (!anfangen) {
							for(int runde=0;runde<2;runde++) {
								RS zs(My,*mytbp,aktc,ZDB);
								vector<instyp> einf;
								rins.tbins(&einf,aktc,0,ZDB?ZDB:runde?obverb:-2,0,0,svec(),0,&csets);
								if (!rins.fnr) break;
							} // 			for(int runde=0;runde<2;runde++)
					} // 					if (!anfangen)
				} // 				if (da.is_open())
			} // 			if (!ru)  else
		} // 		if (ga.is_open())
	} // 	for(int ru=0;ru<2;ru++)
	delete[] fdp;
	/*//
		 svec rueck;
		 systemrueck("sed -n '/output/{s/[^ ]* \\([^;]*\\);/\\1/;p;q}' gl.scr",obverb,oblog,&rueck);
	// wenn (erste) Zeile mit 'output', dann drucke Wort nach ' ' und vor ';' und beende
	// fuer die zweite Zeile könnte das so aussehen:
	*/
	//// sed -n '/output/{x;s/.*/&\\./;/.\\{2\\}/{x;s/[^ ]* \\([^;]*\\);/\\1/;p;q};x}' gl.scr
	/*//
	if (rueck.size()) tbhdscr=rueck[0];
	*/
	return dszahl;
} // long import_firebird(const string& fbdb, const string& fbtb, const string& mydb, const string& *mytbp/*=""*/,int obverb/*=0*/,int oblog/*=0*/)

// Installation zweier Versionen gescheitert, da fuer "gbak -b" eine 32-bit-Version noetig ist und eine solche aus dem Quellcode auch nicht mit:
// zypper in gcc-32bit termcap-32bit ncurses-devel-32bit libstdc++-devel-32bit
// ./configure --prefix=/usr/local/fb21 --exec-prefix=/usr/local/efb21 --datarootdir=/opt/drfb21 --datadir=/opt/dfb21  --enable-superserver --with-service-name=fb21 --with-service-port=3049  --host=i686-linux-gnu "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"
// make
// make install
// systemctl stop firebird
// in /etc/init.d/firebird firebird.pid in fb21.pid umbenennen
// /etc/init.d/firebird in /etc/init.d/fb21 umbenennen
// pkill fbserver
// rm /run/systemd/generator.late/firebird.service
// rm /tmp/firebird.service
// /usr/lib/systemd/system-generators/systemd-sysv-generator
// systemctl daemon-reload
// systemctl start fb21
// erstellbar war und ich fuer zwei binary-Installationen gleichzeitig keine Anleitung fand
// => gleich FirebirdSS 2.1 32-bit installiert lassen und verwenden, zur Sicherheit aber noch die fbk-Dateien erstellen
void hhcl::wandle()
{
 const string ort{"/DATA/down/neu/GL"},
 							datei{"datenbank.zip"},
							gbak{befpfad+"gbak"};
 const string dbname="quelle",
			 tbname="glalle",
			 fbtb{"GL_PCK"};
 svec erg;
 int obverb=1,oblog=0;
 systemrueck("find "+ort+" -name "+datei+" -print0 | /usr/bin/xargs -0 ls -l --time-style=full-iso | sort -k6,7|cut -d/ -f2-",obverb,oblog,&erg);
 for(size_t i=0;i<erg.size();i++) {
  const size_t p1{erg[i].find("_2")},  // 19
				 p2{erg[i].find('/',p1)}; // 27
	const string qdatei{'/'+erg[i]}, // /DATA/down/neu/GL/GL_2015_04/Data/datenbank.zip
				dnam{erg[i].substr(p1,p2-p1)}; // _2015_04
	caus<<violett<<qdatei<<schwarz<<endl;
	const string ausgdir{dir_name(qdatei)+"/x"},
				 fdbalt{ausgdir+"/gelbeliste.fdb"};
	pruefverz(ausgdir);
	systemrueck("chmod 777 "+ausgdir);
	struct stat statq{0};
	if (lstat(fdbalt.c_str(),&statq)) {
		systemrueck("7z e "+qdatei+" -y -o"+ausgdir,obverb+1,oblog);
	}
	systemrueck("chmod 777 -R "+ausgdir);
	const string fbk{ort+"/gl"+dnam+".fbk"};
	if (lstat(fbk.c_str(),&statq)) {
		import_firebird(fdbalt,fbtb,dbname,&tbname,Tx[T_PZN_aus_gelber_Liste]);
		systemrueck(gbak+" -b '"+fdbalt+"' '"+fbk+"' -user sysdba -pas masterke",obverb+1,oblog);
	}
 }
}

void hhcl::pvirtfuehraus() //α
{ //ω
	wandle();
} // void hhcl::pvirtfuehraus  //α


// wird aufgerufen in lauf
void hhcl::virtschlussanzeige()
{   //ω
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige
 
// wird aufgerufen in: main
void hhcl::virtautokonfschreib()
{
// const int altobverb=obverb;
// obverb=1;
	hLog(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein])); //ω
	struct stat kstat{0}; //α
	if (lstat(akonfdt.c_str(),&kstat))
		hccd.obzuschreib=1;
	if (rzf||hccd.obzuschreib) {
		hLog(gruens+Txk[T_schreibe_Konfiguration]+schwarz);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib(); //ω
	} // if (rzf||hccd.obzuschreib) //α
// obverb=altobverb;
} // void hhcl::virtautokonfschreib

hhcl::~hhcl() 
{ //ω
} // hhcl::~hhcl //α

// wird nur im Fall obhilfe==3 nicht aufgerufen
void hhcl::virtlieskonfein()
{
	const int altobverb=obverb;
	//	obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz);
	hcl::virtlieskonfein(); //ω
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
	obverb=altobverb;
} // void hhcl::virtlieskonfein() //ω
int main(int argc,char** argv) //α
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,virtlieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// virtautokonfschreib,update,
	return hhi.retu;
} // int main 

void hhcl::virttesterg()
{
} //ω
