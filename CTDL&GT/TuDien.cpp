#include<iostream>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<fstream>
#define M 101
using namespace std;

struct Word {
	string word;//tu tieng anh
	string type;// tu loai
	string mean;//y nghia cua tu
};

struct DictNode{
	Word word;
	DictNode *next;
};

void init(DictNode *head[]) {
	for(int i=0; i<M; i++){
		head[i] = NULL;
	}
}

int hash(string en) {
	int h = 0;
	for(int i=0; i < en.length(); i++){ //duyet qua tat ca cac ki tu cua tu tieng anh
		h += (int)tolower(en[i])*(i+1); //con don cho cac ki tu dcep kieu nguyen da duoc chuan hoa cve ki tu thuong nhan voi chi so trong chuoi<han che kha nang dung do>
	}
	return h%M;
}

int hashFunc(Word w) {
	return hash(w.word);	
}

DictNode *createWord(Word w) {
	DictNode *word = new DictNode;
	word->word = w;
	word->next = NULL;
}

void addWord(DictNode *head[], Word w) {
	int h = hashFunc(w);
	
	DictNode *r = head[h];//tro den pt dau cua chuoi backet
	DictNode *p = createWord(w);
	
	if(r == NULL) {  //them dau
		head[h] = p;

	}
	else {     //them cuoi 
		int t=hashFunc(r->word);
		
		while(r->next != NULL ) {
			if(t == h)
				break;				
			else	
				r = r->next;
		}	
		if(t != h)
			r->next = p;	
	}	
}

void updateWord(DictNode *head[], Word w) {
	int h = hashFunc(w);
	
	DictNode *r = head[h];
	
	if(r!=NULL) {
		int t=hashFunc(r->word);
		
		do{
			if(t == h){
				r->word = w;
				break;	
			}
	
			r = r->next;
		}while(r!=NULL);	
	}
}

void search(DictNode *head[], string en) {
	int h = hash(en);
	DictNode *r = head[h];
	
	while(r!=NULL) {
		int h1 = hashFunc(r->word);
		if( h== h1) {
			cout<<r->word.word<<"("<<r->word.type<<"): "<<r->word.mean<<endl;
			break;
		}
	}
	r = r->next;
}

void readDict(DictNode *head[]) {
	ifstream f;
	f.open("dict.txt", ios::in);
	
	while(!f.eof()) {
		Word w;
		getline(f, w.word);
		getline(f, w.type);
		getline(f, w.mean);	
		
		addWord(head, w);

	}
	f.close();
}

void deleteWord(DictNode *head[], string en) {
	int h = hash(en);
	DictNode *r = head[h];
	DictNode *prev =NULL;
	
	while(r!=NULL) {
		if( r->word.word.compare(en) ==0) {
			if( prev == NULL){
				head[h]= r->next;
			}
			else{
				prev->next = r->next;				
			}
			r->next = NULL;
			delete(r);
			break;
		}
	}  	
	prev = r;
	r = r->next;
}

void display(DictNode *head[]) {
	for(int i=0; i<M; i++) {
		if(head[i] != NULL){
			cout<<"===BucKet "<<i<<" ===\n";
			DictNode *p = head[i];
			
			while(p!=NULL) {
				cout<<p->word.word<<"("<<p->word.type<<"): "<<p->word.mean<<endl;
				p = p->next;
			}                                                                       
		}
	}
}
int main() {
	
	DictNode *dict[M];
	init(dict);
	
	readDict(dict);
	deleteWord(dict,"book");
	display(dict);
	
	
//	Word w1, w2,w3,w4;
//	w1.word ="Funny";
//	w1.type = "adj";
//	w1.mean = "Hai huoc";
//	
//	w2.word = "bad";
//	w2.type = "adj";
//	w2.mean = "Buon ba, toi te";
//	
//	w3.word ="funny";
//	w3.type = "adj";
//	w3.mean = "Hai huoc";
//	
//	w4.word ="Funny";
//	w4.type = "adj";
//	w4.mean = "vui nhon";
//	
//	addWord(dict, w1);
//	addWord(dict, w3);
//	display(dict);
	
//	cout<<"ket qua cap nhat"<<endl;
//	updateWord(dict,w4);
//	display(dict);
//
//	cout<<"ket qua tim kiem"<<endl;
//	search(dict,"funny");
	
//	return 0;
}

