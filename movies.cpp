#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Movie
{
	private:
		string DVD_Title, Status, Genre;
		string Price;
		string Year, DVD_ReleaseDate, ID;
	public:
		Movie(){};
		Movie(string DVD_Title,string Status,string Price,string Year,string Genre,string DVD_ReleaseDate,string ID){};
		~Movie(){};
		void setDVD_Title(string MyDVD_Title)
		{
			DVD_Title = MyDVD_Title;
		}
		void setStatus(string MyStatus)
		{
			Status = MyStatus;
		}
		void setGenre(string MyGenre)
		{
			Genre = MyGenre;
		}
		void setPrice(string MyPrice)
		{
			Price = MyPrice;
		}
		void setYear(string MyYear)
		{
			Year = MyYear;
		}
		void setDVD_ReleaseDate(string MyDVD_ReleaseDate)
		{
			DVD_ReleaseDate = MyDVD_ReleaseDate;
		}
		void setID(string MyID)
		{
			ID = MyID;
		}
		string getDVD_Title()
		{
			return DVD_Title;
		}
		string getStatus()
		{
			return Status;
		}
		string getGenre()
		{
			return Genre;
		}
		string getPrice()
		{
			return Price;
		}
		string getYear()
		{
			return Year;
		}
		string getDVD_ReleaseDate()
		{
			return DVD_ReleaseDate;
		}
		string getID()
		{
			return ID;
		}
};


string SearchByName(string);

Movie MoviesArray[10];

int main()
{


	Storing();

	int a,b;
	string q,w,e,c;

	cout << "(1)Search and display a movie by" << endl;
	cout << "(2)Compare two movies based on their price information" << endl;
	cout << "(3)List movies based on following genres" << endl;
	cout << "(4)Display Statistics" << endl;
	cout << "(5)Display movies after an input data" << endl;
	cout << "(0)Exit" << endl;
	cin >> a;
	switch(a)
	{
		case 1: cout << "(1)DVD_Title" << endl;
				cout << "(2)ID" << endl;
				cin >> b;
				switch(b)
				{
					case 1: cin >> q;
							SearchByName(q);
                            break;
					case 2: cin >> c;
							//SearchByID(c);
                            break;
				}
				break;
		case 2: cout << "Enter two movies ID to compare: " << endl;
				cin >> w;
				cin >> e;
				//CompareMovies(w, e);
				break;
		case 3: cout << "(1)Suspense" << endl;
				cout << "(2)Foreign" << endl;
				cout << "(3)Comedy" << endl;
				cout << "(4)Western" << endl;
				cout << "(5)Music" << endl;
				cout << "(6)Drama" << endl;
				cin >> b;
				switch(b)
				{
					case 1: //ListGenre(1);
							break;
					case 2: //ListGenre(2);
							break;
					case 3: //ListGenre(3);
							break;
					case 4: //ListGenre(4);
							break;
					case 5: //ListGenre(5);
							break;
					case 6: //ListGenre(6);
							break;
				}
				break;
		case 4: cout << "(1)Display number of each genres" << endl;
				cout << "(2)Display average price " << endl;
				cout << "(3)Display the number of movies whose price is greater than an input " << endl;
				cout << "(4)Display average price of 'Discontinued' movies " << endl;
				cout << "(5)Display average price of 'Out' movies " << endl;
				cout << "(6)Display average price of 'Cancelled' movies " << endl;
				cin >> b;
				switch(b)
				{
					case 1:
							break;
					case 2:
							break;
					case 3:
							break;
					case 4:
							break;
					case 5:
							break;
					case 6:
							break;
				}
				break;
		case 5: cout << "Enter a date: " ;
				cin >> b;
				//DisplayAfterInput(b);
		case 0: break;
	}


}
string SearchByName(string NewName)
{
	for(int i=0;i<10;i++)
	{
		if(MoviesArray[i].getDVD_Title() == NewName)
		{
			return MoviesArray[i].getDVD_Title();
		}
	}

}
/*SearchByID(int NewID)
{
	for(int i=0;i<5195;i++)
	{
		if(MoviesArray[i].getID() == NewID)
		{
			cout << MoviesArray[i].getDVD_Title();
		}
	}
};
CompareMovies(int Mov1, int Mov2)
{
	for(int i=0;i<5195;i++)
	{

	}
};
listGenre(int GenreID)
{
	for(int i=0;i<5195;i++)
	{

	}
};
DisplayAfterInput(int NewDate)
{
	for(int i=0;i<5195;i++)
	{

	}
};*/
void Storing()
{
	ifstream in("DVD_list.txt");
    stringstream buffer;
    buffer << in.rdbuf();
    string DVD_list = buffer.str();
    cout << DVD_list << endl << endl;

    size_t pos1 = 0;
    size_t pos2;
	
	Movie MoviesArray[10];

   for (int x=0; x<=10; x++)
   {
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setDVD_Title(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setStatus(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setPrice(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setYear(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setGenre(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setDVD_ReleaseDate(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
        pos2 = DVD_list.find("        ", pos1);
        MoviesArray[x].setID(DVD_list.substr(pos1, (pos2-pos1)));
        pos1 = pos2+1;
    }
}

