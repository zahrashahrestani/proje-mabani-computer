#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<ctime>

int maxsatr=20,maxsotun=20,maxheyvan=100,maxghaza=100;

struct heyvan{
    char noe;
    int  tedad;
    int  satr;
    int  sotun;
};

void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while(goal > clock());
}

// in tabe check mikonad ba satr va sotun mored nazar, be behesht residim ya na.
int residanBeBehesht(int satr,int sotun,int beheshtHa[][2],int tedadBeheshtha){
    int i;
    for(i=0;i<tedadBeheshtha;i++){
        if(satr==beheshtHa[i][0]  &&  sotun==beheshtHa[i][1]) return 1;
    }

    return 0;
}

// in tabe satr va sotun nazdiktarin behesht ra bar migardanad.
void peidaKardanNazdikTarinBehesht(int beheshtHa[][2],int tedadBeheshtHa,int satrheyvan,int sotunheyvan,int &satrnb,int &sotunnb){
    int faselemin=40;
    int i,faseleSatr,faseleSotun,fasele;

    for(i=0;i<tedadBeheshtHa;i++){
        faseleSatr=satrheyvan-beheshtHa[i][0];
        if(faseleSatr<0) faseleSatr*=-1;

        faseleSotun=sotunheyvan-beheshtHa[i][1];
        if(faseleSotun<0) faseleSotun*=-1;

        fasele=faseleSatr+faseleSotun;
        if(fasele<faselemin){
            faselemin=fasele;
            satrnb=beheshtHa[i][0];
            sotunnb=beheshtHa[i][1];
        }
    }
}

// in tabe heyvan hayi ke dast ma nistand ra harkat midahad.
int harkatHeyvan(char jahan[][20],int satrb,int sotunb,int &satrh,int &sotunh,int AbAdjahan,int beheshtHa[][2],int tedadbeheshtha,char noe){
    if(satrh<satrb){
        if(jahan[satrh+1][sotunh]!='H' && jahan[satrh+1][sotunh]!='.'){
            if(sotunb>sotunh){
                satrh++;
                sotunh++;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh-1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh-1][sotunh-1]='.';
                jahan[satrh][sotunh]=noe;
            }
            else if(sotunb<sotunh){
                satrh++;
                sotunh--;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh+1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh-1][sotunh+1]='.';
                jahan[satrh][sotunh]=noe;
            }
            else{
                if(sotunh+1<=AbAdjahan){
                    satrh++;
                    sotunh++;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh-1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                        return 1;
                    }
                    jahan[satrh-1][sotunh-1]='.';
                    jahan[satrh][sotunh]=noe;
                }
                else{
                    satrh++;
                    sotunh--;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh+1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                        return 1;
                    }
                    jahan[satrh-1][sotunh+1]='.';
                    jahan[satrh][sotunh]=noe;
                }
            }
        }
        else{
            satrh++;
            printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh,satrh,sotunh);
            if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                return 1;
            }
            jahan[satrh-1][sotunh]='.';
            jahan[satrh][sotunh]=noe;
        }
    }
    else if(satrh>satrb){
        if(jahan[satrh-1][sotunh]!='H' && jahan[satrh-1][sotunh]!='.'){
            if(sotunh<sotunb){
                satrh--;
                sotunh++;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh-1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh+1][sotunh-1]='.';
                jahan[satrh][sotunh]=noe;
            }
            else if(sotunh>sotunb){
                satrh--;
                sotunh--;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh+1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh+1][sotunh+1]='.';
                jahan[satrh][sotunh]=noe;
            }
            else{
                if(sotunh+1<=AbAdjahan){
                    satrh--;
                    sotunh++;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh-1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh+1][sotunh-1]='.';
                    jahan[satrh][sotunh]=noe;
                }
                else{
                    satrh--;
                    sotunh--;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh+1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh+1][sotunh+1]='.';
                    jahan[satrh][sotunh]=noe;
                }
            }
        }
        else{
            satrh--;
            printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh,satrh,sotunh);
            if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
            }
            jahan[satrh+1][sotunh]='.';
            jahan[satrh][sotunh]=noe;
        }
    }
    else if(satrh==satrb){
        if(sotunh<sotunb){
            if(jahan[satrh][sotunh+1]!='H' && jahan[satrh][sotunh+1]!='.'){
                if(satrh-1>=0){
                    satrh--;
                    sotunh++;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh-1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh+1][sotunh-1]='.';
                    jahan[satrh][sotunh]=noe;
                }
                else{
                    satrh++;
                    sotunh++;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh-1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh-1][sotunh-1]='.';
                    jahan[satrh][sotunh]=noe;
                }
            }
            else{
                sotunh++;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh,sotunh-1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh][sotunh-1]='.';
                jahan[satrh][sotunh]=noe;
            }
        }
        else if(sotunh>sotunb){
            if(jahan[satrh][sotunh-1]!='H' && jahan[satrh][sotunh-1]!='.'){
                if(satrh-1>=0){
                    satrh--;
                    sotunh--;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh+1,sotunh+1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh+1][sotunh+1]='.';
                    jahan[satrh][sotunh]=noe;
                }
                else{
                    satrh++;
                    sotunh--;
                    printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh-1,sotunh+1,satrh,sotunh);
                    if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                    }
                    jahan[satrh-1][sotunh+1]='.';
                    jahan[satrh][sotunh]=noe;
                }
            }
            else{
                sotunh--;
                printf("%c frome (%d,%d) to (%d,%d)\n",noe,satrh,sotunh+1,satrh,sotunh);
                if(residanBeBehesht(satrh,sotunh,beheshtHa,tedadbeheshtha)==1){
                    return 1;
                }
                jahan[satrh][sotunh+1]='.';
                jahan[satrh][sotunh]=noe;
            }
        }
    }

    return 0;
}







int main(){
    int i,j,abAdJahan,satrbonbast,sotunbonbast,satrheaven,sotunheaven,tedadheyvan;   
    char guneMoredNazar,f;
    char khune,pv;   //pv: parantez va virgul.
    int tedadKhune,ghaza[maxghaza][3];
    char jahan[20][20];
    int q,l,tedadKolHeyvanha=0;
    int satr,sotun,satrnb,sotunnb,vaziat;
    int beheshtHa[100][2],tedadBeheshtha;
    heyvan listHeyvanha[maxheyvan];


    scanf("%d",&abAdJahan);
    for(i=0;i<abAdJahan;i++){
        for(j=0;j<abAdJahan;j++){
            jahan[i][j]='.';
        }
    }

    srand(time(NULL));

    scanf(" %c",&khune);   //khandan khune haye bonbast.
    scanf("%d",&tedadKhune);  //tedad khune haye bonbast.
    i=0;
    while(i<tedadKhune){
        scanf(" %c",&pv);   //(
        scanf("%d",&satrbonbast);
        scanf(" %c",&pv);   //,
        scanf("%d",&sotunbonbast);
        scanf(" %c",&pv);   //)
        jahan[satrbonbast][sotunbonbast]='#';
        i++;
    }
    

    scanf(" %c",&khune);     // khandan khune haye behesht.
    scanf("%d",&tedadBeheshtha);  //khundan tedad khune haye behesht.
    for(i=0;i<tedadBeheshtha;i++){
        scanf(" %c",&pv);   //(
        scanf("%d",&satrheaven);
        scanf(" %c",&pv);   //,
        scanf("%d",&sotunheaven);
        scanf(" %c",&pv);   //)
        beheshtHa[i][0]=satrheaven;
        beheshtHa[i][1]=sotunheaven;
        jahan[satrheaven][sotunheaven]='H';
    }


    for(i=0;i<3;i++){               //khundan mosavi ha.
        scanf(" %c",&pv);
    }


    scanf(" %c",&f);                                //baraye ghaza chon faghat az noe adad hastan yek araye 2 bodi tarif shode.
    i=0;
    do{
        scanf("%d",&ghaza[i][0]);     //energy ghaza
        scanf(" %c",&pv);    //(
        scanf("%d",&ghaza[i][1]);     //satr ghaza
        scanf(" %c",&pv);    //,
        scanf("%d",&ghaza[i][2]);     //sotun ghaza
        scanf(" %c",&pv);   //)
        //jahan[ghaza[i][1]][ghaza[i][2]];
        i++;
        scanf(" %c",&f);                          
    } while(f!=61);                                // anjam bede ta zamani ke mosavi vard shavad.

    for(i=0;i<2;i++){
        scanf(" %c",&pv);
    }

    i=0;                                           // baraye heyvanha chon noe anha ham mohem hast yek struct tarif shode.
    scanf(" %c",&listHeyvanha[i].noe);
    do{
        scanf("%d",&tedadheyvan);
        tedadKolHeyvanha+=tedadheyvan;
        for(j=0;j<tedadheyvan;j++){
            scanf(" %c",&pv);  //(
            scanf("%d",&listHeyvanha[i].satr);
            scanf(" %c",&pv);  //,
            scanf("%d",&listHeyvanha[i].sotun);
            scanf(" %c",&pv);  //)

            jahan[listHeyvanha[i].satr][listHeyvanha[i].sotun]=listHeyvanha[i].noe;

            listHeyvanha[i+1].noe=listHeyvanha[i].noe;
            i++;
        }

        scanf(" %c",&listHeyvanha[i].noe);
    } while(listHeyvanha[i].noe!=61);                       // anjam bede ta zamani ke mosavi vared shavad.


    for(i=0;i<2;i++){
        scanf(" %c",&pv);                        // baghi mosavi ha ra bekhan.
    }

    scanf(" %c",&guneMoredNazar);
    
    printf("jahan:\n");
    for(q=0;q<abAdJahan;q++){
        for(l=0;l<abAdJahan;l++){
            printf(" %c",jahan[q][l]);
        }
        printf("\n");
    }
    
    while(1){
    for(i=0;i<tedadKolHeyvanha;i++){
        if(listHeyvanha[i].noe==guneMoredNazar){
            printf("%c frome ",listHeyvanha[i].noe);
            printf("(%d,%d) to ",listHeyvanha[i].satr,listHeyvanha[i].sotun);
            scanf(" %c",&pv);
            scanf("%d",&satr);
            scanf(" %c",&pv);
            scanf("%d",&sotun);
            scanf(" %c",&pv);

            jahan[listHeyvanha[i].satr][listHeyvanha[i].sotun]='.';
            listHeyvanha[i].satr=satr;
            listHeyvanha[i].sotun=sotun;
            jahan[satr][sotun]=listHeyvanha[i].noe;
            if(residanBeBehesht(satr,sotun,beheshtHa,tedadBeheshtha)==1){
                printf("%c Won!",listHeyvanha[i].noe);
                return 0;
            }
        }
        else{
            peidaKardanNazdikTarinBehesht(beheshtHa,tedadBeheshtha,listHeyvanha[i].satr,listHeyvanha[i].sotun,satrnb,sotunnb); //nb:nazdiktarin behesht.
            vaziat=harkatHeyvan(jahan,satrnb,sotunnb,listHeyvanha[i].satr,listHeyvanha[i].sotun,abAdJahan,beheshtHa,tedadBeheshtha,listHeyvanha[i].noe);
            if(vaziat==1){
                printf("%c Won!",listHeyvanha[i].noe);
                return 0;
            }
            
        }

    }

    printf("jahan:\n");
    for(q=0;q<abAdJahan;q++){
        for(l=0;l<abAdJahan;l++){
            printf(" %c",jahan[q][l]);
        }
        printf("\n");
    }

    sleep(3000);

    }

    return 0;


}