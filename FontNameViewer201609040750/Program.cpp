#include "MyWindow.h"
#include <gtkmm.h>
#include <gtkmm/fontselection.h>
#include <iostream>
#include <fstream>
#include <shlwapi.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#pragma comment(lib, "shlwapi.lib")

// 以下の順序でincludeすると以下のエラーがでる。
// maxの定義名が重複したと思われる。
// stdlib.hとcoverage.hにmaxの定義があるのだろう。
//1>c:\gtkmm\include\pangomm-1.4\pangomm\coverage.h(151): warning C4003: マクロ 'max' に指定された実引数の数が少なすぎます。
//#include <stdlib.h>
//#include <stdio.h>
//#include <locale.h>
//#include <shlwapi.h>
//#include <iostream>
//#include <fstream>
//#include <gtkmm.h>
//#include <gtkmm/fontselection.h>
//#include "MyWindow.h"

int main(int argc, char* argv[])
{
	// http://www.hakodate-ct.ac.jp/~tokai/tokai/gtkmm/img/p18.htm
	Gtk::Main kit( argc, argv );
	MyWindow window;

	::PathRemoveFileSpecA(argv[0]);
	char path[1024];
	memset(path, '\0', 1024);
	strcat_s(path, 1024, argv[0]);
	strcat_s(path, 1024, "\\FontList.tsv");
	std::ofstream stream(path);
	
	typedef Glib::RefPtr< Pango::FontFamily > FFAM;
	typedef Glib::RefPtr< Pango::FontFace > FFACE;

	stream << "FamilyName\tFaces" << std::endl;
	std::list< FFAM > families =  window.get_pango_context()->list_families();
	std::list< FFAM >::iterator it;
	Glib::ustring facesString;
	for( it = families.begin(); it != families.end(); ++it )
	{
		stream << (*it)->get_name() << "\t";

		std::list< FFACE > faces = (*it)->list_faces();
		std::list< FFACE >::iterator it2;
		facesString = "";
		for( it2 = faces.begin(); it2 != faces.end(); ++it2 )
		{
			facesString += (*it2)->get_name() + ",";
		}
		facesString.erase( --facesString.end() );
		stream << facesString << "\n";
	}
	stream.close();
	Gtk::Main::run( window );
	return 0;
}
