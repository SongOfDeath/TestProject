/*
 * Mainy.cpp
 *
 *  
 *      Author: mahir
 */


#include "Mainy.h"
#include <windows.h>

#include<iostream>
#include <io.h>   // For access().
#include <sys/types.h>  // For stat().
#include <sys/stat.h>   // For stat().
#include <string>

#include<sstream>
#include<windows.h>
#include<wininet.h>
using namespace std;
using std::string;

bool foundGame = false;
namespace test {


Mainy::Mainy() {
	// TODO Auto-generated constructor stub
	//
}

Mainy::~Mainy() {
	// TODO Auto-generated destructor stub
}

} /* namespace test */

/*
 * mainClass.cpp
 *
 *  Created on: 23 Tem 2018
 *      Author: maho
 */



string GetActiveWindowTitle()
{
 char wnd_title[256];
 HWND hwnd=GetForegroundWindow(); // get handle of currently active window
 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 return wnd_title;
}


void sendMailToMe()
{
    string strPath = "c:\\send-mail.ps1";
//access function:
    //The function returns 0 if the file has the given mode.
    //The function returns –1 if the named file does not exist or does not have the given mode
    if(access(strPath.c_str(),0) == 0)
    {

           system("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
           system("start powershell.exe c:\\send-mail.ps1");
           system("cls");
    }
    else
    {
           system("cls");
           cout << "File is not exist";
           system("pause");
    }
}
/*
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////SEND SMS//////////////////////////////////////////////
string encode(string url)
{
char *hex = "0123456789abcdef";
stringstream s;

for(unsigned int i = 0; i < url.length(); i++)
{
	byte c = (char)url.c_str()[i];
	if( ('a' <= c && c <= 'z')
	|| ('A' <= c && c <= 'Z')
	|| ('0' <= c && c <= '9') ){
		s << c;
	} else {
		if(c == ' ') s << "%20";
		else
		s << '%' << (hex[c >> 4]) << (hex[c & 15]);
	}
}

return s.str();
}


void sendSMS()
{
	// the SMS gateway's host
	// and port
	string host       = "localhost";
	int port          = 9502;

	// username
	// and password
	string username   = "admin";
	string password   = "abc123";

	// message
	string message    = "This is a test SMS.";

	// originator's phone number
	string originator = "+905313029943";

	// recipient's phone number.
	// to send the SMS to multiple recipients, separate them by using commas without spaces
	string recipient  = "+905313029943";

	// preparing the HTTPRequest URL
	stringstream url;
		url << "/api?action=sendmessage&username=" << encode(username);
		url << "&password=" << encode(password);
		url << "&recipient=" << encode(recipient);
		url << "&messagetype=SMS:TEXT&messagedata=" << encode(message);
		url << "&originator=" << encode(originator);
		url << "&responseformat=xml";

	// create socket
	HINTERNET inet = InternetOpen("Ozeki", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	// open connection and bind it to the socket
	HINTERNET conn = InternetConnect(inet, host.c_str() , port, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
	HINTERNET a;
	// open the HTTP request

	HINTERNET sess = HttpOpenRequest(conn, "GET", url.str().c_str(), "HTTP/1.1", NULL, NULL, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_RELOAD, 0);
	// check errors
	int error = GetLastError();
	if(error == NO_ERROR)
	{
		// send HTTP request
		HttpSendRequest(sess, NULL, 0, NULL,0);

		// receive HTTP response

		int size = 1024;
		char *buffer = new char[size + 1];
		DWORD read;
		int rsize = InternetReadFile(sess, (void *)buffer, size, &read);
		string s = buffer;
		s = s.substr(0, read);

		// check status code
		int pos = s.find("<statuscode>0</statuscode>");

		// if statuscode is 0, write "Message sent." to output
		// else write "Error."
		if(pos > 0) cout << "Message sent." << endl;
		else cout << "Error." << endl;
	}

	system("pause");
	}
///////////////////////////////////SEND SMS////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
*/
int main(void){
	//bool foundGame = false;
	//sendMailToMe();
	//sendSMS();
    while(foundGame==false)
    {

    	Sleep(150);
    	//count++;
    	//cout<<count<<"\n";
    	//cout<<GetActiveWindowTitle()<<"\n";
    	if(GetActiveWindowTitle()=="Dota 2")
    	{
    		foundGame = true;
    		sendMailToMe();
    		//SetActiveWindowTitle("dota 2");
    	}

    }
    //return 0;
}

bool IsForegroundProcess(DWORD pid)
{
   HWND hwnd = GetForegroundWindow();
   if (hwnd == NULL) return false;

   DWORD foregroundPid;
   if (GetWindowThreadProcessId(hwnd, &foregroundPid) == 0) return false;

   return (foregroundPid == pid);
}



	// encoding converts characters that are not allowed in a URL into character-entity equivalent


/*
//char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"owningrazor1@gmail.com\" --mail-rcpt \"owningrazor1@gmail.com\" --ssl -u owningrazor1@gmail.com:rexxar123 -T \"hello.txt\" -k --anyauth";
//WinExec(command, SW_HIDE);

//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

if (PathFileExists(fileName))
{
 	ostringstream os;
 	os << "-ExecutionPolicy ByPass -NoProfile -NonInteractive -WindowStyle Hidden -File \"" << CT2A(theApp.GetApplicationFolder()) << "Prep-OptionsFile.ps1" << "\" \"" << CT2A(fileName) << "\" \"" << CT2A(ext) << "\"";
 	string op = "open";
 	string ps = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\PowerShell.exe";
 	string param = os.str();
 	DWORD res = (int)ShellExecuteA(NULL, op.c_str(), ps.c_str(), param.c_str(), NULL, SW_HIDE);
}
*/


/*
string strPath = "c:\\send-mail.ps1";
//access function:
//The function returns 0 if the file has the given mode.
//The function returns –1 if the named file does not exist or does not have the given mode
if(access(strPath.c_str(),0) == 0)
{

       system("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
       system("start powershell.exe c:\\send-mail.ps1");
       system("cls");
}
else
{
       system("cls");
       cout << "File is not exist";
       system("pause");
}
*/
//int count =1;
