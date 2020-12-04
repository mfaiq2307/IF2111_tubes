#include "mesinkata.h" 

boolean EndKata; 
Kata CKata;


void IgnoreBlank_File() { 
/* Mengabaikan satu atau beberapa BLANK 
I.S.: CC sembarang 
F.S.: CC ≠ BLANK */ 
/* Kamus Lokal */ 
/* Algoritma */ 
    while (CC == BLANK) { 
        ADV_File(); 
    } /* CC != BLANK */ 
} 

void STARTKATA_File(char *filename) { 
/* I.S.: CC sembarang 
F.S.: EndKata = true, dan CC = Mark;  
atau EndKata = false, CKata adalah kata yang sudah 
diakuisisi, 
CC karakter pertama sesudah karakter terakhir kata */ 
/* Kamus Lokal */ 
/* Algoritma*/
    START_File(filename); 
    IgnoreBlank_File();
    if (CC == MARK) {
        EndKata = true; 
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata_File();
    } 
} 

void ADVKATA_File() { 
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi 
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,  
CC adalah karakter pertama dari kata berikutnya,  
mungkin MARK  
Proses: Akuisisi kata menggunakan procedure SalinKata */ 
/* Kamus Lokal */ 
/* Algoritma*/ 
    IgnoreBlank_File(); 
    if (CC == MARK) { 
        EndKata = true; 
    } else /* CC != MARK */ { 
        SalinKata_File(); 
    } 
} 

void SalinKata_File() { 
/* Mengakuisisi kata, menyimpan dalam CKata 
I.S.: CC adalah karakter pertama dari kata 
F.S.: CKata berisi kata yang sudah diakuisisi;  
CC = BLANK atau CC = MARK;  
CC adalah karakter sesudah karakter terakhir yang  
diakuisisi */ 
/* Kamus Lokal */ 
    int i; /* definisi */ 
    /* Algoritma*/ 
    i = 0; /* inisialisasi */ 
    boolean cont = true;
    CKata = Purify(CKata);
    while ((CC != MARK) && (CC != BLANK)) {
        /*printf("%c",CC);*/
        CKata.TabKata[i] = CC;
        /*printf("masuk%c",CKata.TabKata[i]);*/ 
        ADV_File();
        if ((CC == NEWLINE) || (CC == DELIMITER)){
            break;
        }
        i++; 
    } /* CC = MARK or CC = BLANK */ 
    CKata.Length = i;
    Clean(&CKata);
    Space(&CKata);
    printf("!"); 
}

void SalinKata_Input(Kata *CKata){
    char command[NMax];
    int c;
    int i = 0;
    while (((c = (char)fgetc(stdin)) != '\n') && (i < NMax)){
        command[i] = c;
        i++;
    }
    CKata->TabKata[i] = '\0'; 
    CKata->Length = i;
    int j = 0;
    while (j < NMax){
        CKata->TabKata[j] = command[j];
        j++;
    }
}
boolean IsStringSama(char* string1, char* string2){
    int i = 0;
    boolean sama = true;
    while((string1[i] != '\0') && (string2[i] != '\0') && (sama)){
        if(string1[i] != string2[i]){
            sama = false;
        }
        i++;
    }

    return sama;
}

Kata Purify(Kata Kotor){
    int i = 0;
    while (i < NMax){
        Kotor.TabKata[i] = ENDSTR;
        i++;
    }
    Kotor.Length = 0;
    return Kotor;
}
void Clean(Kata *Kotor){
    int i = 0;
    if ((Kotor->TabKata[0] == DELIMITER) || (Kotor->TabKata[0] == NEWLINE)){
        while (i < Kotor->Length){
            Kotor->TabKata[i] = Kotor->TabKata[i+1];
            i++;
        }
        Kotor->TabKata[Kotor->Length] = ENDSTR;
        Kotor->Length = Kotor->Length - 1;
    }
}

void Space(Kata *Kotor){
    int i = 0;
    while (i < Kotor->Length){
        if (Kotor->TabKata[i] == '"'){
            Kotor->TabKata[i] = ' ';
        }
        i++;
    }
}

void SalinKata_Item() { 
/* Mengakuisisi kata, menyimpan dalam CKata 
I.S.: CC adalah karakter pertama dari kata 
F.S.: CKata berisi kata yang sudah diakuisisi;  
CC = BLANK atau CC = MARK;  
CC adalah karakter sesudah karakter terakhir yang  
diakuisisi */ 
/* Kamus Lokal */ 
    int i; /* definisi */ 
    /* Algoritma*/ 
    i = 0; /* inisialisasi */ 
    while ((CC != MARK) && (CC != ',')) {
        /*printf("%c",CC);*/
        CKata.TabKata[i] = CC;
        /*printf("masuk%c",CKata.TabKata[i]);*/ 
        ADV_File(); 
        i++; 
    } /* CC = MARK or CC = BLANK */ 
    CKata.Length = i; 
}

int KataToInt(Kata String){
    int angka = 0;
    int i = String.Length;
    int j = 0;
    while (j < i){
        angka = CharToInt(String.TabKata[j]) + (10 * angka);
        j++;
    }
    return angka;
}

Kata IntToKata(int angka){
    Kata string;
    int temp;
    int i = 0;
    int j = 0;
    while(Pangkat(10,i) <= angka){
        i++;
    }
    i--;
    if (angka >= 0){
        if (angka != 0){
            while (i != -1){
                if(angka % Pangkat(10,i) == 0){
                    string.TabKata[j] = IntToChar(angka/Pangkat(10,i));
                    angka = 0;
                }
                else{
                    temp = angka/(Pangkat(10,i));
                    string.TabKata[j] = IntToChar(temp);
                    angka = angka % (temp * Pangkat(10,i));
                }
                i--;
                j++;
            }
            string.TabKata[j] = '\0';
            string.Length = j;
        }else{
            string.TabKata[j] = '0';
            string.Length = 1;
        }
        return string;
    }else{
        printf("Fitur belum tersedia, mohon maaf :D");
    }
}

