//BINARNO ISKLANO DREVO

#include <iostream>
using namespace std;

struct Node {
	int key = 0;
	Node* father = nullptr;
	Node* leftSon = nullptr;
	Node* rightSon = nullptr;
};

void menu() {
	cout << endl;
	cout << "Binarno iskalno drevo - izbira: " << endl;
	cout << endl;
	cout << "1) Vnos podatka" << endl;
	cout << "2) Urejen izpis vrednosti" << endl;
	cout << "3) Izpis povezav" << endl;
	cout << "4) Iskanje" << endl;
	cout << "5) Poisci minimum in maksimum" << endl;
	cout << "6) Poisci predhodnika in naslednika" << endl;
	cout << "7) Brisi vrednost" << endl;
	cout << "8) Konec" << endl;
	cout << endl;
	cout << "Izbira: ";
}


void insert(int stevilo, Node*& koren) {
	Node* y = nullptr;
	Node* temp = koren;

	while (temp != nullptr) {				//poišèemo "primeren" kazalec oz. mesto za nov element
		y = temp;
		if (stevilo < temp->key) {
			temp = temp->leftSon;
		}
		else if (stevilo > temp->key) {
			temp = temp->rightSon;
		}
		else
			cout << "ERROR";
	}

	Node* new_element = new Node;
	new_element->key = stevilo;				//ustvarimo nov element s kazalcem father na prej najdeno mesto
	new_element->father = y;

	if (y == nullptr) {
		koren = new_element;				//èe nismo našli primernega mesta za nov objekt, pomeni da drevo še ne obstaja
	}
	else {
		if (new_element->key < y->key) {	//èe je nov element manjši od "najdenega mesta", postane leftSon
			y->leftSon = new_element;		
		}
		else {
			y->rightSon = new_element;		//... drugaèe rightSon
		}
	
	}
}


Node* search(int stevilo, Node*& koren) {
	Node* temp = koren;

	while (temp != nullptr) {
		if (stevilo == temp->key) {
			return temp;
		}
		if (stevilo < temp->key) {
			temp = temp->leftSon;
		}
		else {
			temp = temp->rightSon;
		}
	}

	return temp;
}


void urejenIzpis(Node*& x) {
	if (x != nullptr) {
		urejenIzpis(x->leftSon);
		cout << x->key << " ";
		urejenIzpis(x->rightSon);
	}
}


void izpisPovezav(Node*& x) {
	if (x->leftSon != nullptr) {
		cout << x->key << "->" << x->leftSon->key << endl;
		izpisPovezav(x->leftSon);
	}

	if (x->rightSon != nullptr) {
		cout << x->key << "->" << x->rightSon->key << endl;
		izpisPovezav(x->rightSon);
	}
}


Node* minimum(Node*& koren) {
	Node* temp = koren;
	while (temp->leftSon != nullptr) {
		temp = temp->leftSon;
	}

	return temp;
}

Node* maximum(Node*& koren) {
	Node* temp = koren;
	while (temp->rightSon != nullptr) {
		temp = temp->rightSon;
	}

	return temp;
}


Node* predhodnik(Node* temp) {
	if (temp->leftSon != nullptr) {
		return maximum(temp->leftSon);
	}

	Node* y = temp->father;
	while (y != nullptr && temp == y->leftSon) {
		temp = y;
		y = y->father;
	}

	return y;
}

Node* naslednik(Node* temp) {
	if (temp->rightSon != nullptr) {
		return minimum(temp->rightSon);
	}

	Node* y = temp->father;
	while (y != nullptr && temp == y->rightSon) {
		temp = y;
		y = y->father;
	}

	return y;
}

void brisiScenarij1_2(Node*& temp, Node*& koren) {
	Node* x;
	if (temp->leftSon != nullptr) {
		x = temp->leftSon;
	}									//kazalec x kaže na levi ali desni sin elementa
	else {
		x = temp->rightSon;		
	}

	if (x != nullptr) {
		x->father = temp->father;		//oèe brisanega števila postane oèe sina brisanega števila 
	}

	if (temp->father == nullptr) {		//èe brišemo prvi element
		koren = x;
	}
	else {
		if (temp == temp->father->leftSon) {
			temp->father->leftSon = x;		//prevežemo da starševski element kaže na kazalec x
		}
		else {
			temp->father->rightSon = x;
		}
	}
}

void brisi(Node*& temp, Node*& koren) {
	Node* y = new Node;

	if (temp->leftSon == nullptr || temp->rightSon == nullptr) {
		brisiScenarij1_2(temp, koren);
	}
	else {
		y = naslednik(temp);
		int vrednost = y->key;
		brisiScenarij1_2(y, koren);
		temp->key = vrednost;
	}
}

int main(){
	bool running = true;
	int izbira;

	Node* koren = nullptr;
	int stevilo;

	Node* Minimum;
	Node* Maximum;
	Node* Predhodnik;
	Node* Naslednik;
	Node* pointerToSt;

	do {
		cout << endl;
		menu();
		cin >> izbira;
		switch (izbira) {
		case 1:
			cout << "Katero stevilo zelite vnesti: ";
			cin >> stevilo;
			while (search(stevilo, koren) != nullptr) {
				cout << "Stevilo ze obstaja. Vnes novo: ";
				cin >> stevilo;
			}
			insert(stevilo, koren);
			break;
		case 2:
			if (koren == nullptr) {
				cout << "Drevo je prazno!" << endl;
			}
			else {
				urejenIzpis(koren);
			}
			break;
		case 3:
			if (koren == nullptr) {
				cout << "Drevo je prazno!" << endl;
			}
			else {
				izpisPovezav(koren);
			}
			break;
		case 4:
			cout << "Katero stevilo iscete: ";
			cin >> stevilo;
			if (search(stevilo, koren) != nullptr) {		//èe vrne kazalec na to število, potem število obstaja, drugaèe ne (vrne nullptr)
				cout << "Stevilo obstaja v drevesu." << endl;
			}
			else {
				cout << "Stevilo v drevesu ne obstaja." << endl;
			}
			break;
		case 5:			
			if (koren == nullptr) {
				cout << "Drevo je prazno!";
			}
			else {
				Minimum = minimum(koren);
				Maximum = maximum(koren);
				cout << "Najmanjsa vrednost v drevesu: " << Minimum->key /*minimum(koren)*/ << endl;
				cout << "Najvecja vrednost v drevesu: " << Maximum->key /*maximum(koren)*/;
			}
			break;
		case 6:
			cout << "Predhodnik & naslednik katerega stevila: ";
			cin >> stevilo;
			if(search(stevilo, koren) == nullptr) {
				cout << "Stevilo ne obstaja.";
				break;
			}
			else {
				Predhodnik = predhodnik(search(stevilo, koren));
				Naslednik = naslednik(search(stevilo, koren));
				if (Predhodnik == nullptr) {
					cout << "Predhodnik ne obstaja!" << endl;
				}
				else {
					cout << "Predhodnik: " << Predhodnik->key /*predhodnik(search(stevilo))*/ << endl;
				}

				if (Naslednik == nullptr) {
					cout << "Naslednik ne obstaja!" << endl;
				}
				else {
					cout << "Naslednik: " << Naslednik->key /*naslednik(search(stevilo))*/ << endl;
				}
			}


			break;
		case 7:
			cout << "Katero stevilo zelite zbrisat: ";
			cin >> stevilo;
			if (search(stevilo, koren) == nullptr) {
				cout << "Stevilo ne obstaja.";
				break;
			}
			else {
				pointerToSt = search(stevilo, koren);
				brisi(pointerToSt, koren);
			}
			break;
		case 8:
			running = false;
			delete koren;
			break;
		default:
			cout << "Narobe izbira!" << endl;
			break;
		}
	} while (running);
	
	return 0;
}

