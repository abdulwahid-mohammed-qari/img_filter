// Ahmed bandar bin khunfur  20210800    11410120210800@stud.cu.edu.eg
//Abdulwahid mohammed qari   20210735    11410120210735@stud.cu.edu.eg
//Abdalbadea adel abas       20210770    11410120210770@stud.cu.edu.eg





#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
using namespace std;

//----------------------------------------
unsigned char image[SIZE][SIZE][RGB];
unsigned char new_image[SIZE][SIZE][RGB];
//-------------------------------------------

int GX[3][3] = {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}
};


int GY[3][3] = {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}
};

//-------------------------------------------

void load_image();
void load_image_1();
void save_image();
void save_image_1();
void black_white_image();
void image_inverter ();
void merge_filter();
void flip_image_upside_down();
void flip_image_left_right();
void image_rotate();
void lighten();
void darken();
void filter_7();
void image_enlarge();
void shrink_image();
void shrink_image_2();
void shrink_image_3();
void mirror_1();
void mirror_2();
void mirror_3();
void mirror_4();
void shuffle_image ();
void blur_image();


//--------------------------------------------

int main(){
    int choice;
    int operation;
    bool checker = true;
    char reuse;
    while (checker) {
        cout << "1.Black and White" << endl << "2.Invert" << endl << "3.Merge" << endl << "4.Flip"
             << endl << "5.Rotate" << endl << "6.Darken and Lighten" << endl << "7.Detect Edges"<< endl
             << "8. Enlarge" << endl << "9. Shrink" << endl << "10. Mirror" << endl
             << "11. Shuffle" << endl << "12. Blur" << endl;
        cin >> choice;


        if (choice == 1) {
            load_image();
            black_white_image();
            save_image();
        }


        if (choice == 2){
            load_image();
            image_inverter();
            save_image_1();
        }


        if (choice == 3){
            load_image();
            load_image_1();
            merge_filter();
            save_image_1();
        }


        if (choice == 4){
            cout << " 1.flip vertically" << endl << "2. flip horizontally" << endl;
            cin >> operation;
            if (operation == 1){

                load_image();
                flip_image_left_right();
                save_image();
            }

            if (operation == 2){
                load_image();
                flip_image_upside_down();
                save_image();
            }
        }


        if (choice == 5){
            load_image();
            image_rotate();
            save_image_1();
        }

        if (choice == 6){
            cout << " 1. lighten " << endl << " 2. darken" << endl;
            cin >> operation;

            if (operation == 1){
                load_image();
                lighten();
                save_image_1();
            }

            if (operation == 2){
                load_image();
                darken();
                save_image_1();
            }

        }

        if (choice == 7){
            load_image();
            filter_7();
            save_image_1();
        }

        if (choice == 8){
            load_image();
            image_enlarge();
            save_image_1();
        }

        if (choice == 9){
            cout << "  1. TO 1/2 " << endl <<"  2. TO 1/3 " << endl << "  3. TO 1/4 " << endl;
            cin >> operation;
            if (operation == 1){
                load_image();
                shrink_image();
                save_image_1();
            }

            if (operation == 2 ){
                load_image();
                shrink_image_2();
                save_image_1();
            }

            if (operation == 3){
                load_image();
                shrink_image_3();
                save_image_1();
            }

        }


        if (choice == 10){
            cout << " 1.Down" << endl << " 2.Right" << endl << " 3.Left" << endl << " 4.Upper" << endl;
            cin >> operation;
            if (operation == 1){
                load_image();
                mirror_1();
                save_image();
            }

            if (operation == 2){
                load_image();
                mirror_2();
                save_image();
            }


            if (operation == 3){
                load_image();
                mirror_3();
                save_image();
            }

            if (operation == 4){
                load_image();
                mirror_4();
                save_image();
            }

        }

        if (choice == 11){
            load_image();
            shuffle_image ();
            save_image_1();
        }

        if (choice == 12){
            load_image();
            blur_image();
            save_image();
        }

        cout << "if you want to continue press any button & if you want to exit press (N)";
        cin >> reuse;
        if ((reuse == 'n') || (reuse == 'N')){
            checker = false;
        }
    }

}

//-------------------------------------------------------------------

void load_image(){
    char image_file_name[100];

    cout << " Enter the source image file name :  " ;
    cin >> image_file_name;

    // add .bmp
    strcat(image_file_name,".bmp");
    readRGBBMP(image_file_name,image);
}

//------------------------------------------------------------------

void load_image_1(){
    char image_file_name[100];

    cout << " Enter the source image file name :  ";
    cin >> image_file_name;

    // addd .bmp
    strcat(image_file_name,".bmp");
    readRGBBMP(image_file_name,new_image);
}

//----------------------------------------------------------------

void save_image(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

//-------------------------------------------------------------------

void save_image_1(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, new_image);
}

//---------------------------------------------------------------------
// filter _ 1

void black_white_image(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (image[i][j][0] + image[i][j][1] + image[i][j][2] >= 128 * 3){
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else{
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }

        }
    }
}

//---------------------------------------------------------------------------------
// filter _  2

void image_inverter() {          // invert the pixels of colored image
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = 0 ; j < SIZE ; j++){
            for(int k = 0 ; k < RGB ; k++ ){
                new_image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}

//---------------------------------------------------------------------------------
// filter _ 3

void merge_filter(){
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 255; ++j) {
            for (int k = 0; k < 3; ++k) {
                new_image[i][j][k] = (image[i][j][k]+new_image[i][j][k]) / 2 ;

            }

        }
    }
}

//------------------------------------------------------------------------------------
// filter _ 4

void flip_image_upside_down(){
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE / 2; j++){
            for (int k = 0; k < RGB; ++k) {
                swap(image[i][j][k],image[i][SIZE - j][k]);
            }
        }
    }
}

void flip_image_left_right(){
    for (int i = 0; i < SIZE/2; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                swap(image[i][j][k] , image[255-i][j][k]);
            }
        }
    }
}

//------------------------------------------------------------------------------------
// filter _ 5

void image_rotate(){
    int rotate_number;
    cout<< "Enter 90 for rotate 90 " << endl << "  Enter 180 for rotate 180"
        << endl << "  Enter 270 for rotate 270 " << endl;
    cin>>rotate_number;
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            for(int k = 0 ; k < RGB ; k++){
                if(rotate_number == 90)
                    new_image[i][j][k] = image[SIZE - j][i][k];
                else if(rotate_number == 180)
                    new_image[i][j][k] = image[SIZE - i][SIZE - j][k];
                else if(rotate_number == 270)
                    new_image[i][j][k] = image[j][SIZE - i][k];
            }
        }
    }
}

//---------------------------------------------------------------------------------------
// filter _ 6

void lighten(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {
                unsigned char l = 0.5*image[i][j][k];
                unsigned char ll = (127 + l);
                if (ll <= 0){
                    ll = ll + 225 ;
                }
                new_image[i][j][k] = ll;
            }
        }
    }
}


void darken(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {
                image[i][j][k] = image[i][j][k] - 0.5*(image[i][j][k]);
                new_image[i][j][k] = image[i][j][k];
            }
        }
    }
}

//------------------------------------------------------------------------------
// filter _ 7

void filter_7(){
    int  i_index , j_index  ,pixel_valueR , pixel_valueG , pixel_valueB ;
    double GX_valueR , GY_valueR , GX_valueG , GY_valueG , GX_valueB , GY_valueB ;
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 255; ++j) {
            for (int k = 0; k < 255; ++k) {
                GX_valueR =0 , GY_valueR =0 , GX_valueG=0, GY_valueG =0,GX_valueB =0 , GY_valueB =0 ;
                for (int l = 0; l < 3; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        i_index = (i-1)+l;
                        j_index = (j-1)+m;
                        if (i_index < 0 || i_index > 255 || j_index < 0 || j_index > 255 )
                            continue;
                        GX_valueR += image[i_index][j_index][0]*GX[l][m];
                        GY_valueR += image[i_index][j_index][0]*GY[l][m];
                        GX_valueG += image[i_index][j_index][2]*GX[l][m];
                        GY_valueG += image[i_index][j_index][2]*GY[l][m];
                        GX_valueB += image[i_index][j_index][1]*GX[l][m];
                        GY_valueB += image[i_index][j_index][1]*GY[l][m];

                    }

                }
                pixel_valueR = round(sqrt((GX_valueR  * GX_valueR)+(GY_valueR * GY_valueR) ));
                if (pixel_valueR > 255){
                    pixel_valueR = 255;
                }
                new_image[i][j][0] = pixel_valueR;

                pixel_valueG = round(sqrt( (GX_valueG * GX_valueG)+(GY_valueG * GY_valueG)));
                if (pixel_valueG > 255){
                    pixel_valueG = 255;
                }
                new_image[i][j][2] = pixel_valueG;

                pixel_valueB = round(sqrt((GX_valueB * GX_valueB)+(GY_valueB * GY_valueB)));
                if (pixel_valueB > 255){
                    pixel_valueB = 255;
                }
                new_image[i][j][1] = pixel_valueB;
            }

        }

    }
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = 0 ; j < SIZE ; j++){
            for(int k = 0 ; k < RGB ; k++ ){
                new_image[i][j][k] = 255 - new_image[i][j][k];
            }
        }
    }

}

//-----------------------------------------------------------------------------------------------
// filter _ 8

void image_enlarge(){
    int part;
    // choose the part you want to enlarge
    cout<<"Enter 1 for part 1 " << endl << "  Enter 2 for part 2 "
        << endl << "  Enter 3 for part 3 " << endl << "  Enter 4 for part 4  " << endl;
    cin>>part;

    // enlarge part 1 [0][0]
    if(part == 1) {
        for(int i = 0 ; i < SIZE / 2 ; i++) {
            for(int j = 0 ; j < SIZE / 2 ; j++) {
                for(int k = 0 ; k < RGB ; k++){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
        int o = 0;
        int n = 0 ;
        // to repeat the pixels to be enlarged to 256
        for(int k = 0 ; k < SIZE ; k += 2) {
            for(int m = 0 ; m < SIZE ; m += 2) {
                for(int i = 0 ; i < RGB  ; i++ ){
                    image[k][m][i] = new_image[o][n][i];
                    image[k + 1][m][i] = new_image[o][n][i];
                    image[k][m + 1][i] = new_image[o][n][i];
                    image[k + 1][m + 1][i] = new_image[o][n][i];
                }
                n++;
            }
            n = 0;
            o++;
        }
        for(int i = 0 ; i < SIZE ; i++) {
            for(int j = 0 ; j < SIZE ; j++) {
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
        // enlarge part 2 [0][128]
    else if(part == 2){
        for(int i = 0 ; i < SIZE / 2 ; i++){
            for(int j = SIZE / 2 ; j < SIZE ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
        int o = 0;
        int n = 128 ;
        // to repeat the pixels to be enlarged to 256
        for(int k = 0 ; k < SIZE ; k += 2) {
            for(int m = 0 ; m < SIZE ; m += 2) {
                for(int i = 0 ; i < RGB ; i++ ){
                    image[k][m][i] = new_image[o][n][i];
                    image[k + 1][m][i] = new_image[o][n][i];
                    image[k][m + 1][i] = new_image[o][n][i];
                    image[k + 1][m + 1][i] = new_image[o][n][i];
                }
                n++;
            }
            n = 128;
            o++;
        }
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
        //  enlarge part 3 [128][0]
    else if(part == 3){
        for(int i = SIZE / 2 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE / 2 ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
        int o = 128;
        int n = 0 ;
        // to repeat the pixels to be enlarged to 256
        for(int k = 0 ; k < SIZE ; k += 2){
            for(int m = 0 ; m < SIZE ; m += 2){
                for(int i = 0 ; i < RGB ; i++ ){
                    image[k][m][i] = new_image[o][n][i];
                    image[k + 1][m][i] = new_image[o][n][i];
                    image[k][m + 1][i] = new_image[o][n][i];
                    image[k + 1][m + 1][i] = new_image[o][n][i];
                }
                n++;
            }
            n = 0;
            o++;
        }
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
        // enlarge part 4 [128][128]
    else if(part == 4){
        for(int i = SIZE / 2 ; i < SIZE ; i++){
            for(int j = SIZE / 2 ; j < SIZE ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
        int o = 128;
        int n = 128 ;
        // to repeat the pixels to be enlarged to 256
        for(int k = 0 ; k < SIZE ; k += 2){
            for(int m = 0 ; m < SIZE ; m += 2){
                for(int i = 0 ; i < RGB ; i++ ){
                    image[k][m][i] = new_image[o][n][i];
                    image[k+1][m][i] = new_image[o][n][i];
                    image[k][m+1][i] = new_image[o][n][i];
                    image[k+1][m+1][i] = new_image[o][n][i];
                }
                n++;
            }
            n = 128;
            o++;
        }
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                for(int k = 0 ; k < RGB ; k++ ){
                    new_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
}

//---------------------------------------------------------------------------------
// filter _ 9

void moveQuarter( int i, int j ){
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=2){
        for (int l = 0; l < 3; ++l) {
            j = temp;
            for (int z=0; z< SIZE; j++ , z+=2){
                new_image[i][j][l]=image[k][z][l];
            }
        }
    }
}

void moveQuarter_2( int i, int j ){
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=3){
        for (int l = 0; l < 3; ++l) {
            j = temp;
            for (int z=0; z< SIZE; j++ , z+=3){
                new_image[i][j][l]=image[k][z][l];
            }
        }
    }
}

void moveQuarter_3( int i, int j ){
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=4){
        for (int l = 0; l < 3; ++l) {
            j = temp;
            for (int z=0; z< SIZE; j++ , z+=4){
                new_image[i][j][l]=image[k][z][l];
            }
        }
    }
}


void shrink_image(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter(0,0);
    }
}

void shrink_image_2(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter_2(0,0);
    }
}

void shrink_image_3(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter_3(0,0);
    }
}

//-------------------------------------------------------------------
// filter _ A _  Mirror

// down
void mirror_1(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j][0] = image[SIZE-(i)][(j)][0];
            image[i][j][1] = image[SIZE-(i)][(j)][1];
            image[i][j][2] = image[SIZE-(i)][(j)][2];

        }
    }
}

// right
void mirror_2(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j][0] = image[(i)][256-(j)][0];
            image[i][j][1] = image[(i)][256-(j)][1];
            image[i][j][2] = image[(i)][256-(j)][2];

        }
    }
}

// left
void mirror_3(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256/2; ++j) {
            image[i][j+128][0] = image[(i)][128-(j)][0];
            image[i][j+128][1] = image[(i)][128-(j)][1];
            image[i][j+128][2] = image[(i)][128-(j)][2];

        }
    }
}

// upper
void mirror_4(){
    for (int i = 0; i < 256/2; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i+128][j][0] = image[128-(i)][(j)][0];
            image[i+128][j][1] = image[128-(i)][(j)][1];
            image[i+128][j][2] = image[128-(i)][(j)][2];

        }
    }
}

//-----------------------------------------------------------------------------------
// filter _ B

void shuffle_image (){

    // it is the old sort of the photo
    string old_sort[4] = {"1" , "2" , "3" , "4"};

    // to enter new sort for the photo
    string new_sort[4];
    cout<<" enter the new sort : "<<endl;
    for(int j = 0 ; j < 4 ; j++){
        cin>>new_sort[j];
    }

    for (int i = 0 ; i < 4 ; i++){           // to loop on the 4 quarters of the photo by loopping on the new sort of the photo

        if(new_sort[i] == old_sort[i]){  // if there is a quarter in the new sort equal to the same quarter in the old photo put it in the same position (quarter)

            if(new_sort[i] == "1" ){  // quarter 1 in the same position

                for(int i = 0 ; i < SIZE / 2 ; i++) {
                    for(int j = 0 ; j < SIZE / 2 ; j++) {
                        for(int o = 0 ; o < RGB ; o++ ){
                            new_image[i][j][o] = image[i][j][o];
                        }
                    }
                }
            }
            if(new_sort[i] == "2"){   // quarter 2 in the same position

                for(int i = 0 ; i < SIZE / 2 ; i++){
                    for(int j = SIZE / 2 ; j < SIZE ; j++){
                        for(int o = 0 ; o < RGB ; o++ ){
                            new_image[i][j][o] = image[i][j][o];
                        }
                    }
                }
            }
            if(new_sort[i] == "3"){   // quarter 3 in the same position

                for(int i = SIZE / 2 ;i < SIZE ; i++){
                    for(int j = 0 ; j < SIZE / 2 ; j++){
                        for(int o = 0 ; o < RGB ; o++ ){
                            new_image[i][j][o] = image[i][j][o];
                        }
                    }
                }
            }
            if(new_sort[i] == "4"){   // quarter 4 in the same position

                for(int i = SIZE / 2 ; i <SIZE ; i++){
                    for(int j = SIZE / 2 ; j < SIZE ; j++){
                        for(int o = 0 ; o < RGB ; o++ ){
                            new_image[i][j][o] = image[i][j][o];
                        }
                    }
                }
            }
        }
        else if (new_sort[i] != old_sort[i]){  // if the quarter in the new sort not equal to the same position of the quarter in the old photo

            if(old_sort[i] == "1"){  // the origin quarter 1 position in the original photo

                if(new_sort[i] == "4" ){  // the new postion of quarter 4 in the the original quarter 1 in the new photo
                    int i = 0 ;
                    int j = 0 ;
                    for(int k = SIZE / 2 ; k < SIZE ; k++){
                        for(int m = SIZE / 2 ; m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];

                            }
                            j++;
                        }
                        i++;
                        j = 0 ;
                    }
                }
                if(new_sort[i] == "3" ){   // the new postion of quarter 3 in the the original quarter 1 in the new photo
                    int i = 0 ;
                    int j = 0 ;
                    for(int k = SIZE / 2 ; k < SIZE ; k++){
                        for(int m = 0 ; m < SIZE /2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o]=image[k][m][o];

                            }
                            j++;
                        }
                        i++;
                        j=0 ;
                    }
                }
                if(new_sort[i] == "2" ){   // the new postion of quarter 2 in the the original quarter 1 in the new photo
                    int i = 0 ;
                    int j = 0 ;
                    for(int k = 0 ; k < SIZE / 2 ; k++){
                        for(int m = SIZE / 2 ; m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j=0 ;
                    }
                }
            }
            if(old_sort[i] == "2"){   // the origin quarter 2 position in the original photo

                if(new_sort[i] == "4" ){   // the new postion of quarter 4 in the the original quarter 2 in the new photo
                    int i = 0 ;
                    int j = SIZE / 2 ;
                    for(int k = SIZE / 2 ; k < SIZE  ; k++){
                        for(int m = SIZE / 2 ; m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];

                            }
                            j++;
                        }
                        i++;
                        j = SIZE / 2 ;
                    }
                }
                if(new_sort[i] == "3" ){    // the new postion of quarter 3 in the the original quarter 2 in the new photo
                    int i = 0 ;
                    int j = SIZE / 2 ;
                    for(int k = SIZE / 2 ; k < SIZE ; k++){
                        for(int m = 0 ; m < SIZE / 2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j=SIZE/2;
                    }
                }
                if(new_sort[i] == "1"){   // the new postion of quarter 1 in the the original quarter 2 in the new photo
                    int i = 0 ;
                    int j = SIZE / 2;
                    for(int k = 0 ; k < SIZE / 2 ; k++){
                        for(int m = 0 ; m < SIZE / 2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j = SIZE / 2;
                    }
                }
            }
            if(old_sort[i] == "3"){   // the origin quarter 3 position in the original photo

                if(new_sort[i] == "4" ){  // the new postion of quarter 4 in the the original quarter 3 in the new photo
                    int i = SIZE / 2 ;
                    int j = 0 ;
                    for(int k = SIZE / 2 ; k < SIZE  ; k++){
                        for(int m = SIZE / 2 ; m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o]=image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j=0 ;
                    }
                }
                if(new_sort[i] == "2" ){  // the new postion of quarter 2 in the the original quarter 3 in the new photo
                    int i = SIZE / 2 ;
                    int j = 0 ;
                    for(int k = 0 ;k < SIZE / 2 ; k++){
                        for(int m = SIZE / 2  ;m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j = 0 ;
                    }
                }
                if(new_sort[i] == "1"){   // the new postion of quarter 1 in the the original quarter 3 in the new photo
                    int i = SIZE / 2;
                    int j = 0;
                    for(int k = 0 ; k < SIZE / 2 ; k++){
                        for(int m = 0 ; m < SIZE / 2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j = 0;
                    }
                }
            }
            if(old_sort[i] == "4"){   // the origin quarter 4 position in the original photo
                if(new_sort[i] == "3" ){    // the new postion of quarter 3 in the the original quarter 4 in the new photo
                    int i = SIZE / 2 ;
                    int j = SIZE / 2 ;
                    for(int k = SIZE / 2 ; k < SIZE ; k++){
                        for(int m = 0 ; m < SIZE / 2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];

                            }
                            j++;
                        }
                        i++;
                        j = SIZE / 2 ;
                    }
                }
                if(new_sort[i] == "2" ){    // the new postion of quarter 2 in the the original quarter 4 in the new photo
                    int i = SIZE / 2 ;
                    int j = SIZE / 2 ;
                    for(int k = 0 ; k < SIZE / 2 ; k++){
                        for(int m = SIZE / 2 ; m < SIZE ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j = SIZE / 2 ;
                    }
                }
                if(new_sort[i] == "1"){    // the new postion of quarter 1 in the the original quarter 4 in the new photo
                    int i = SIZE / 2;
                    int j = SIZE / 2;
                    for(int k = 0 ; k < SIZE / 2 ; k++){
                        for(int m = 0 ; m < SIZE / 2 ; m++){
                            for(int o = 0 ; o < RGB ; o++ ){
                                new_image[i][j][o] = image[k][m][o];
                            }
                            j++;
                        }
                        i++;
                        j = SIZE / 2;
                    }
                }
            }
        }
    }
    for(int i =0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            for(int o = 0 ; o < RGB ; o++ ){
                new_image[i][j][o];
            }
        }
    }
}

//-------------------------------------------------------------------------------------
// filter _ C

void blur_image() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] = ( image[i][j][k]+image[i+1][j+1][k]+image[i+1][j][k]+image[i][j+1][k]+image[i-1][j-1][k]+image[i-1][j][k]+image[i][j-1][k]
                                   +image[i+4][j+4][k]+image[i+4][j][k]+image[i][j+4][k]+image[i-4][j-4][k]+image[i-4][j][k]+image[i][j-4][k]
                                   +image[i+3][j+3][k]+image[i+3][j][k]+image[i][j+3][k]+image[i-3][j-3][k]+image[i-3][j][k]+image[i][j-3][k]
                                   +image[i+2][j+2][k]+image[i+2][j][k]+image[i][j+2][k]+image[i-2][j-2][k]+image[i-2][j][k]+image[i][j-2][k] )/25 ;
            }
        }
    }
}
