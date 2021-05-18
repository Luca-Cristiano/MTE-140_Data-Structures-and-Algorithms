//Names: Aidan Walker, Bryan Guan, Luca Cristiano
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

class ArtCollectionTest;

class Artwork 
{
    private:
        string artistName;
        unsigned int yearMade;
        string title;
    public:
  
        Artwork (){
            artistName = "";
            yearMade = 0;
            title = "";
        }
        Artwork (string artistName0, string title0, unsigned int yearMade0) : 
		artistName(artistName0), yearMade(yearMade0), title(title0){}

        string get_artistName() const {
            return artistName;
        }

        void set_artistName(string artistName0) {
            artistName = artistName0;
        }

        string get_title() const {
            return title;
        }

        void set_title(string title0){
            title = title0;
        }

        unsigned int get_yearMade() const {
            return yearMade;
        }

        void set_yearMade(unsigned int yearMade0) {
            yearMade = yearMade0;
        }

        bool operator==(Artwork const & otherArt) const {
            return (title == otherArt.get_title() && yearMade == otherArt.get_yearMade() && artistName == otherArt.get_artistName());
        }
        
        void print_Artwork()const{
		
			cout << "Artist Name: " << artistName << endl;
			cout << "Title: " << title << endl;
			cout << "Year Made: " << yearMade << endl;
		
		}
		friend class ArtCollectionTest;
};

class SoldArtwork: public Artwork
{
	private:
		string custName, custAddress;
		double saleAmount;
		Artwork a;	
	
	public:
		SoldArtwork()
		{
	 	custName = " ";
			custAddress = " ";
			saleAmount = 0;
		}
		
		SoldArtwork(string custName_, string custAddress_, double saleAmount_, Artwork a_):
		custName(custName_), custAddress(custAddress_), saleAmount(saleAmount_), Artwork(a_) {}
		
		bool operator==(const SoldArtwork& otherArtwork) const
		{
			return (custName == otherArtwork.get_custName() && custAddress == otherArtwork.get_custAddress() && saleAmount == otherArtwork.get_saleAmount() && get_artistName() == otherArtwork.get_artistName() && get_title() == otherArtwork.get_title() && get_yearMade() == otherArtwork.get_yearMade());
		}
		
		string get_custName() const {
            return custName;
        }

        string get_custAddress() const {
            return custAddress;
        }
        
        double get_saleAmount() const {
            return saleAmount;
        }
        
        Artwork get_a() const {
     	   return a;
    	}
		
		void print_soldArtwork()const{
			
			print_Artwork();
			cout << "Customer Name: " << custName << endl;
			cout << "Customer Address: " << custAddress << endl;
			cout << "Sale Amount: " << saleAmount << endl;
			
		}
		friend class ArtCollectionTest;		
};


class ArtCollection
{
    private:
        vector<Artwork> artPieces;
        vector<SoldArtwork> SoldartPieces;
    public:
        ArtCollection(){
            artPieces;
            SoldartPieces;
        }
        bool insert_artwork(const Artwork & artwork_info){
            for (int index = 0; index< artPieces.size(); index++){
                if (artPieces[index] == artwork_info){
                    return false;
                }
            }
            artPieces.push_back(artwork_info);
            return true;
        }
        bool insert_Soldartwork(const SoldArtwork & artwork_info){
            for (int index = 0; index< SoldartPieces.size(); index++){
                if (SoldartPieces[index] == artwork_info){
                    return false;
                }
            }
            SoldartPieces.push_back(artwork_info);
            return true;
        }


        bool sell_artwork(const SoldArtwork & artwork_info){
            int spot = -1;
            for (int index = 0; index< artPieces.size(); index++){
                if (artPieces[index] == static_cast<Artwork>(artwork_info)){
                    spot = index;
                }
            }
            if (spot == -1){
                return false;
            }
            insert_Soldartwork (artwork_info);
            artPieces.erase (artPieces.begin() + spot);
            return true;
	}

    vector<Artwork> get_artPieces() const {
        return artPieces;
    }

    vector<SoldArtwork> get_Soldartpieces() const {
        return SoldartPieces;
    }

    bool operator==(ArtCollection const & otherCollection){
        bool present = true;
        for (int index = 0; index < otherCollection.get_Soldartpieces().size() && present == true; index++){
            present = false;
            for (int index1 = 0; index1 < SoldartPieces.size() && present == false; index1++){
                if (otherCollection.get_Soldartpieces()[index] == SoldartPieces[index1]){
                    present = true;
                }
                
            }
        }
        if(!present)
        	return false;
        
        for (int index = 0; index < otherCollection.artPieces.size() && present == true; index++){
            present = false;
            for (int index1 = 0; index1 < artPieces.size() && present == false; index1++){
                if (otherCollection.artPieces[index] == artPieces[index1]){
                    present = true;
                }
            }
        }
        return present;
    }

	void print_Collection()const{
	
		for (int index = 0; index < artPieces.size(); index++){
			
			artPieces[index].print_Artwork();
			
		}
		
		for (int index = 0; index < SoldartPieces.size(); index++){
			
			SoldartPieces[index].print_soldArtwork();
			
		}
	}

    friend ArtCollection operator+(ArtCollection& collection1, ArtCollection& collection2);
    friend class ArtCollectionTest;
};


ArtCollection operator+(ArtCollection & collection1, ArtCollection & collection2){
    ArtCollection newCollection;
	
	for (int index = 0; index < collection1.get_artPieces().size(); index++){
        newCollection.insert_artwork(collection1.get_artPieces()[index])
    ;}
	
    for (int index = 0; index < collection2.get_artPieces().size(); index++){
        newCollection.insert_artwork(collection2.get_artPieces()[index])
    ;}

	for (int index = 0; index < collection1.get_Soldartpieces().size(); index++){
        newCollection.insert_Soldartwork(collection1.get_Soldartpieces()[index])
	;}

    for (int index = 0; index < collection2.get_Soldartpieces().size(); index++){
        newCollection.insert_Soldartwork(collection2.get_Soldartpieces()[index])
    ;}
    
    return newCollection;
}

class ArtCollectionTest
{
	ArtCollection ac, ac2, ac3, test_combine, ac4, ac5, ac6;
	Artwork a1, a2, a3, a4, a5, a6;
	SoldArtwork sa1, sa2;
	vector<Artwork> test_Artwork;
	vector<SoldArtwork> test_SoldArtwork;
	 
	
	public:
		void setup()
		{
			a1 = Artwork ("a", "b", 1);
			a2 = Artwork ("c", "d", 2);
			a3 = Artwork ("e", "f", 3);
			a4 = Artwork ("a", "b", 1);
			a5 = Artwork ("g", "h", 4);
			a6 = Artwork ("i", "j", 5);
			test_Artwork.push_back(a1);
			test_Artwork.push_back(a2);
			test_Artwork.push_back(a3);
			
			sa2 = SoldArtwork ("Orange", "Cow", 38, a3);
			
			ac2.insert_artwork(a1); 
			ac2.insert_artwork(a2); 
			ac2.insert_artwork(a3); 

			ac3.insert_artwork(a1); 
			ac3.insert_artwork(a2); 
			ac3.insert_artwork(a3);
			
			test_combine.insert_artwork(a5);
			test_combine.insert_artwork(a6);
			test_combine.insert_Soldartwork(sa2);
		}
		void test_insert_artwork()
		{
			for(int i = 0; i < test_Artwork.size(); i++)
			{
				ac.insert_artwork(test_Artwork.at(i));
			}
			
				assert(ac.get_artPieces() == test_Artwork);
				cout<<"Artwork successfully inserted."<<endl;
		}
		void test_duplicate()
		{
			ac.insert_artwork(test_Artwork.at(0));
			assert(ac.get_artPieces() == test_Artwork);
			cout<<"Duplicate artwork was not inserted."<<endl;		
		}
		void test_sell_artwork()
		{
			test_Artwork.push_back(a1);			
			sa1 = SoldArtwork ("Yo", "Bro", 23, a3);
			test_Artwork.pop_back();
			test_Artwork.pop_back();
			test_SoldArtwork.push_back(sa1);
			
			assert(ac.sell_artwork(sa1));
			
			assert(ac.get_artPieces() == test_Artwork && ac.get_Soldartpieces() == test_SoldArtwork);
			cout<<"Artwork successfully removed." << endl;
		}
		void test_insert_soldartwork()
		{
			sa1 = SoldArtwork ("Orange", "Cow", 38, a3);
			test_SoldArtwork.push_back(sa1);
			
			ac.insert_Soldartwork(sa1);
			
			assert(ac.get_Soldartpieces() == test_SoldArtwork);
			cout<<"Soldartwork inserted successfully"<< endl;
		}
		void test_Constructors ()
		{
			Artwork cT1;
			SoldArtwork cT2;
			
			cT1.print_Artwork();
			cT2.print_soldArtwork();
			
			Artwork cT3 = Artwork ("x", "y", 10);
			SoldArtwork cT4 = SoldArtwork ("l", "m", 98, a1);
			
			assert(cT3.get_artistName() == "x" && cT3.get_title() == "y" && cT3.get_yearMade() == 10);
			assert(cT4.get_custName() == "l" && cT4.get_custAddress() == "m" && cT4.get_saleAmount() == 98 && static_cast<Artwork>(cT4) == a1);
		}
		void test_operatorEqual()
		{
			assert(a1 == a4);
			cout<<"Operator overloaded == for artworks is successful."<<endl;
			
			assert(sa1 == sa2);
			cout<<"Operator overloaded == for sold artworks is successful."<<endl;
			assert(ac2 == ac3);
			cout<<"Operator overloaded == for artwork collection is successful."<<endl;		
		}
		void test_operatorPlus()
		{
			ac4.insert_artwork(a5);
			ac4.insert_artwork(a6);
			ac5.insert_artwork(a6);
			ac5.insert_Soldartwork(sa2);
			ac6 = ac4 + ac5;	
			assert((ac4 + ac5) == test_combine);
		}
		
		
		void run_test()
		{
			setup();
			test_insert_artwork();
			test_duplicate();
			test_sell_artwork();
			test_insert_soldartwork();
			test_operatorEqual();
			test_Constructors ();
			test_operatorPlus();
			cout<<"--------------------------"<<endl;
			test_combine.print_Collection();
			cout<<"--------------------------"<<endl;
			ac6.print_Collection();
		}
			
};


int main(){
	
	ArtCollectionTest at;
	at.run_test();
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*
Artwork successfully inserted.
Duplicate artwork was not inserted.
Artwork successfully removed.
Soldartwork inserted successfully
Operator overloaded == for artworks is successful.
Operator overloaded == for sold artworks is successful.
Operator overloaded == for artwork collection is successful.
Customer Name:
Customer Address:
Sale Amount: 0
--------------------------
Artist Name: g
Title: h
Year Made: 4
Artist Name: i
Title: j
Year Made: 5
Artist Name: e
Title: f
Year Made: 3
Customer Name: Orange
Customer Address: Cow
Sale Amount: 38
--------------------------
Artist Name: g
Title: h
Year Made: 4
Artist Name: i
Title: j
Year Made: 5
Artist Name: e
Title: f
Year Made: 3
Customer Name: Orange
Customer Address: Cow
Sale Amount: 38
*/
