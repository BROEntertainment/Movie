#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Movie
{
	private:
		string DVD_Title, Status, Genre;
		double Price;
		string Year, DVD_ReleaseDate, ID;
	public:
		Movie(){};
		Movie(string DVD_Title,string Status,double Price,string Year,string Genre,string DVD_ReleaseDate,string ID){};
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
		void setPrice(double MyPrice)
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
		double getPrice()
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

Movie MoviesArray[10];

string CompareMovies(string, string);
string SearchByName(string);
string SearchByID(string);
int DisplayNumberGenres();

int main()
{
double p = 6.99, o = 14.99;
string l = "Discontinued", k = "Discontinued";
string qwe="anan", qwer="baban";
MoviesArray[0].setPrice(p);
MoviesArray[0].setStatus(l);
MoviesArray[0].setDVD_Title(qwe);
MoviesArray[1].setPrice(o);
MoviesArray[1].setStatus(k);
MoviesArray[1].setDVD_Title(qwer);


    double sum = 0, average = 0;
	int a,b,counter = 0;
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
							SearchByID(c);
                            break;
				}
				break;
		case 2: cout << "Enter two movies ID to compare: " << endl;
				cin >> w;
				cin >> e;
				CompareMovies(w, e);
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
					case 1: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Suspense")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
							break;
					case 2: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Foreign")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
							break;
					case 3: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Comedy")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
							break;
					case 4: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Western")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
							break;
					case 5: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Music")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
							break;
					case 6: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getGenre() == "Drama")
                                    cout << MoviesArray[i].getDVD_Title();
                            }
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
					case 1: DisplayNumberGenres();
							break;
					case 2: for(int i=0;i<10;i++) //i değeri kadar girdi yapılırsa çalışır.
                            {
                                    sum = sum + MoviesArray[i].getPrice();
                                    counter++;
                            }
                                    average = sum / counter;
                                    cout << average;
							break;
					case 3:
							break;
					case 4: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getStatus() == "Discontinued")
                                    counter = counter + 1;
                                    sum = sum + MoviesArray[i].getPrice();
                            }
                                    average = sum / (double)counter;
                                    cout << average;
							break;
					case 5: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getStatus() == "Out")
                                    counter = counter + 1;
                                    sum = sum + MoviesArray[i].getPrice();
                            }
                                    average = sum / (double)counter;
                                    cout << average;
							break;
					case 6: for(int i=0;i<10;i++)
                            {
                                if(MoviesArray[i].getStatus() == "Canceled")
                                    counter = counter + 1;
                                    sum = sum + MoviesArray[i].getPrice();
                            }
                                    average = sum / (double)counter;
                                    cout << average;
							break;
				}
				break;
		case 5: cout << "Enter a date: " ;
				cin >> b;
				//DisplayAfterInput(b);
		case 0: break;
	};

return 0;
}



string SearchByName(string NewName)
{
	for(int i=0;i<10;i++)
	{
		if(MoviesArray[i].getDVD_Title() == NewName)
		{
			cout << MoviesArray[i].getDVD_Title();
		}
	}

}
string SearchByID(string NewID)
{
	for(int i=0;i<10;i++)
	{
		if(MoviesArray[i].getID() == NewID)
		{
			cout << MoviesArray[i].getDVD_Title();
		}
	}
}
string CompareMovies(string Mov1, string Mov2)
{
    bool v=false ,b=false;
    double qw,we;
	for(int i=0;i<10;i++)
	{
        if(MoviesArray[i].getID() == Mov1)
            v = true;
            
        if(MoviesArray[i].getID() == Mov2)
            b = true;
            
        while(b = true && v = true)


	}
}
int DisplayNumberGenres()
{
    int
    for(int i=0; i<10; i++)
    {
        switch(MoviesArray[i].getGenre())
        {
            case
        }
    }
}
/*DisplayAfterInput(int NewDate)
{
	for(int i=0;i<5195;i++)
	{

	}
}
void Storing()
{

}*/

