#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

struct coupleCharOcc
{
    wchar_t valueChar;
    int occ;
};
//déclaration des procédures et fonctions

void analyseLexicale(wchar_t *);
//procédure d'inversion de phrase
void reverseWords(wchar_t *);
//procédure d'Affichage du nombre d'occurrence de chaque lettre trié sur les lettres
void occCharacterAlphabetical(wchar_t*);
//procédure d'Affichage du nombre d'occurrence de chaque lettre, trié sur les occurrences
void occCharacterOccurence(wchar_t *);
//procédure de comparaison des couples char occurrence par l'occurrence des char
int compareOccurence( const void*, const void* );
//procédure de comparaison des couples char occurrence par les char
int compareAlpha(const void*, const void* );
//fonction de comptage du nombre de char disctinct
int countDistinctChar(wchar_t *);
//procédure de comptage des différentes lettres dans une phrase
void countChar(wchar_t*,struct coupleCharOcc *,int);

int main()
{
    //fixer la variable locale LC_ALL pour traiter tout type de caractère.
    setlocale(LC_ALL,"");
    wprintf(L"Analyse lexicale simplifiée \n");
    //exemple de fonctionnement de l'analyse lexicale
    wprintf(L"démonstration avec la phrase : Développez 10 fois plus vite \n");
    wchar_t *phrase= L"Développez 10 fois plus vite";
    //appel à la procédure d'analyse lexicale
    analyseLexicale(phrase);
    free(phrase);
    wprintf(L"Appuyez sur entrée\n");
    getchar();
    wprintf(L" démonstration avec un seul mot  (anticonstitutionnellement) \n");
    wchar_t *phrase2=L"anticonstitutionnellement";
    analyseLexicale(phrase2);
    free(phrase2);
    wprintf(L"Appuyez sur entrée\n");
    getchar();
    wprintf(L"démonstration avec aucun caractère\n");
    wchar_t *phrase3=L"";
    analyseLexicale(phrase3);
    free(phrase3);
    wprintf(L"Appuyez sur entrée\n");
    getchar();
    wprintf(L"démonstration avec 1000 mots (lorem ipsum)\n");
    wchar_t *phrase4=L" Has j'ai accusatores ductor quae cogebatur has praeceptum turmis abnuens metu nos kiwi quae Vrsicinus metu ruinarum Nisibi turmis discriminis quaesitoresque metu palamve a a militum ex sibi oblatrantibus praeceptum exhalaret exitialis exhalaret anxius forensibus iurgiis ex reclamans varietates has isdem tumor accusatores dispicere nos exhalaret milesque inplorans clam exitialis sui iurgiis subsidia qui et edocebat quorum adulatorum discriminis edocebat bellicosus longe exitialis metu et dispicere inplorans militum turmis litis forensibus et cogebatur has et palamve nos praeceptum tuebatur Nisibi inplorans quae abnuens iurgiis bellicosus quam has obsecuturos agitabantur cogebatur tumor Vrsicinus longe discriminis turmis semper exitialis iurgiis sed cum Quod trahebatur honoratorum damnabatur partes delatus esset insulari quasi aut inter postulatus militarium insulari beluae capite hoc suos rumore postulatus honoratorum aut honoratorum aut beluae partes postulatus damnabatur bonorum et hoc aut militarium enim catenarum insimulatus nominatus tenus bonorum militarium suos aut aut bonorum trahebatur urgente esset modum aut aut aut fovisse aut esset hostiles aut esset bonorum hostiles solo inimico aut hostiles hoc multatione quasi vel vel tenus vel esset sufficiente trahebatur et insimulatus delatus esset modum beluae beluae onere capite aut catenarum fovisse esset et solitudine tenus quod iniecto nominatus nobilis militarium et rumore hostiles damnabatur nominatus sufficiente Porrigitur rex auxit limes indicat dextra supercilia regna gentibus rectum usque Alexandri auxit et modum usque efficaciae pelagi iure gentibus quam cum iure Alexandri limes Nicator modum efficaciae longum porrigitur Seleucus cognomentum regna fragoribus longum Persidis longum plagam inpetrabilis usque fragoribus ut fragoribus successorio inpetrabilis pelagi dextra conterminans pelagi ut in gentibus Nili cum Macedonis cum dextra Saracenis efficaciae ab Persidis ad plagam Saracenis Alexandri inpetrabilis gentibus ab indicat laeva et quam iure Nili fragoribus vero limes longum dextra in indicat Saracenis plagam in Persidis ripis rex Macedonis pelagi obitum Seleucus regna Nili patens gentibus regna inpetrabilis Macedonis vero vero façon Lacessens et multitudine obvios et et et globis serpentes moliens dispersos ambitus sed et nunc et et isdem nata lacessens repellere et hic dispersos plana dispersos plurima superabatur per educata montium eminus ut editos ambitus eos plana ingenti quisque globis missilibus lacessens ut et loca serpentes aliquotiens pro ut castella quisque ululatu et quae pro et quae educata mollia lacessens quae pro loca montium quisque conterminant plurima moliens nata editos eminus latius editos quae quae persultat et missilibus et sed et loca latius viribus globis educata recurvosque pro et ululatu missilibus serpentes serpentes ut eminus multitudine persultat loca quae serpentes à partir Vero iam exitialis frumenta tamen captis propinquantis cibos vero copiis propinquantis captis navigiis navigiis iam iam horrebant captis solitarum aerumnas captis ipsi clausos rerum navigiis angebat inediae flumen captis alimentorum quidem copiis cibos horrebant alimentorum vehebant aerumnas consumendo vehementer cibos angebat copiis vero quae adfluebant cibos cibos rerum captis vehebant solitarum per consumendo captis navigiis solitarum ipsi horrebant exitialis inediae aerumnas quidem vehementer consumendo aerumnas copiis adfluebant angebat angebat copiis horrebant vehebant consumendo Isauri captis rerum solitarum vero Isauri ipsi solitarum alimentorum vehebant vero Isauri consumendo quidem inediae ipsi per propinquantis vero ipsi frumenta quae vero Isauri per ipsi flumen été Quantum sit quantum dare domo in ad ad me isti dicam M existimatis pudore istam primum etiam in ut cum vos Crassi hunc deinde vos flore dicam Crassi aut quantum omnem tantum cum vidit locum quantum Caelium dicam tantum erudiretur est potuit ad patre hoc nemo Crassi Qui mecum ut Nam cum isti ad deductum esse Caelium ut tantum orationem suspicioni erudiretur patris est disciplinaque isti quantum nisi huic pudore continuo ad Caelium primum hunc aut deinde illo togam omnem Nam hoc hunc a loco continuo deinde vidit quantum illo primum dicam tantum cum M deditšnihil potuit Caeli pudore nemo In praefecto propensior mandaverat perferens protectoribus ad super quod praefecti Montius propensior prodesse adimenda indigna vita post scholarum deiectas decere deiectas custodiam mollius si commune si prodesse praefecti commotus est primos securius adlocutus Constantii docens fidis praefecto super consulens Montius prodesse statuas placeret acer post ad quidem in sonu si adimenda obiurgatorio adlocutus quo statuas addensque sed adlocutus fidis quaestor quod mandaverat ille fidis super super cogitari deiectas custodiam acer praefecti decere haec primos sonu post quidem decere conperto id Constantii custodiam haec nec tunc mandaverat est iniusta quaestor consulens addensque fidis commune est protectoribus conperto praefecti si consulens Montius Adseclae disciplinarum adseclae extrusis praecipites milia milia tria pellerentur minimarum formidatam tenerentur liberalium liberalium liberalium sectatoribus paucis alimentorum liberalium tempus urbe respiratione liberalium ita cum inpendio alimentorum cum cum praecipites totidemque et magistris ulla alimentorum saltatricum ulla peregrini ventum haut ventum sectatoribus quidem ad tempus ita saltatricum magistris ut milia ventum choris ut indignitatis alimentorum ad ulla pellerentur cum ad quique ad sectatoribus peregrini indignitatis tempus id ob haut pellerentur quique ob haut adseclae veri ita sine veri adseclae dudum quique adseclae remanerent remanerent choris quidem ad ab tenerentur formidatam est quique ad veri tria tria ad urbe remanerent quidem Ducitur tribunos Epigonus dilancinantium spiritum dignitatem ostendens Eusebium agitari qui increpabat ab et Eusebium magna Lycia inter increpabat nec si Epigonus Epigonum agitari hi sint non ducitur inter spiritum e quaestor inter nec orator ducitur efflaturus et manus dilancinantium dilancinantium Lycia agitari increpabat nequid sed non et Lycia insimulasset Montius industria philosophus Epigonus novas ostendens sed intepesceret sint et Emissa quaestor nequid ducitur intepesceret nec e et qui armorum inter industria quia inter professionem philosophus sed si et tribunos quaerebatur non nec tribunos industria dignitatem hos industria nec ostendens magna armorum tribunos et manus promittentes ducitur cum Eusebius spiritum et zéro Serenianus an cupiebat portenderetur suffragatione rettulimus portenderetur rettulimus duce ad operiebat familiarem suffragatione duce cunctum cunctum tempore in misisse artibus duce cupiebat quaeritatum Celsen ei imperium iure caput suum pileo misisse cupiebat postulatus cupiebat Celsen fatidicum ex quo duce ad iure ignavia Celsen caput populatam imperii et ut misisse pileo familiarem Celsen cupiebat et Serenianus Serenianus ut duce absolvi duce ei convictus pileo rettulimus populatam ei firmum ei ad imperium ut iure aperte rettulimus firmum expresse duce templum qua ad ei convictus maiestatis fatidicum in ut expresse postulatus incantato caput pileo Celsen populatam maiestatis ex qua";
    analyseLexicale(phrase4);
    free(phrase4);
    wprintf(L"Appuyez sur entrée\n");
    getchar();
    wprintf(L"démonstration avec uniquement des chiffres\n");
    wchar_t *phrase5= L"10  1545 4545 0 54";
    analyseLexicale(phrase5);
    free(phrase5);
    wprintf(L"Appuyez sur entrée pour terminer\n");
    getchar();
    return 0;
}

void analyseLexicale(wchar_t *phrase)
{
    //on vérife que la phrase contient au moins un caractères autre que espace
    if((phrase== L"")||(phrase== L" "))
    {
        printf("phrase vide pas d'analyse possible \n");
    }
    else
    {
        // applique les trois pocédures d'analyse
        reverseWords(phrase);
        occCharacterAlphabetical(phrase);
        occCharacterSortOccurence(phrase);
    }
}

void reverseWords(wchar_t *phrase)
{
    wchar_t str[wcslen(phrase)];
    //on copie la phrase dans une variable temporaire
    wcscpy(str,phrase);
    //on va compter le nombre de mots dans la phrase
    int nbMots = 1;
    int i=0;
    for( i=0; i<wcslen(str); i++)
    {
        if (str[i]== ' ' && (str[i+1]!=' ' ) &&(i+1<wcslen(str)) )
        {
            nbMots++;
        }
    }
    //on crée un tableau de mots
    wchar_t *reversedString[nbMots];
    //on coupe la phrase à chaque espace (peut poser des problèmes sous linux)
    wchar_t *token = wcstok (str, L" ");
    int nbMotsRestant=nbMots;
    while (token != NULL)
    {
        //on copie en partant de la fin la phrase dans le tableau de mots
        reversedString[nbMotsRestant-1]=token;
        token = wcstok (NULL, L" ");
        nbMotsRestant--;
    }

    wprintf(L"la phrase inversée est: ");
    for(i=0; i<nbMots; i++)
    {
        //on affiche la phrase inversée
        wprintf(L"%ls",reversedString[i]);
        printf(" ");
    }
    printf("\n");
}

void occCharacterAlphabetical(wchar_t* phrase)
{
    //combien de lettre dans la phrase
    int nbDistinctChar = countDistinctChar(phrase) ;
    //création d'un tableau de couple
    struct coupleCharOcc arrCharCount[nbDistinctChar];
    //on compte le nombre d'occurrence de chaque lettre
    countChar(phrase,&arrCharCount,nbDistinctChar);
    //on trie le tableau par ordre alphabétique
    qsort(arrCharCount,nbDistinctChar,sizeof(struct coupleCharOcc),compareAlpha);
    int o=0;
    wprintf(L"** lettres triées par ordre alphabétique ** \n");
    //on affiche les couples lettre nombre d'occurrence
    for(o=0; o<nbDistinctChar; o++)
    {
        printf("%c=",arrCharCount[o].valueChar);
        printf("%d ",arrCharCount[o].occ);
    }
    printf("\n");
}

void occCharacterSortOccurence(wchar_t* phrase)
{
    //combien de lettre dans la phrase
    int nbDistinctChar = countDistinctChar(phrase) ;
    //création d'un tableau de couple
    struct coupleCharOcc arrCharCount[nbDistinctChar];
    //on compte le nombre d'occurrence de chaque lettre
    countChar(phrase,&arrCharCount,nbDistinctChar);
    //on trie le tableau par nombre croissant d'occurrence
    qsort(arrCharCount,nbDistinctChar,sizeof(struct coupleCharOcc),compareOccurence);
    int o=0;
    wprintf(L"** lettres triées par nombre d'occurrence ** \n");
    //on affiche les couples lettre nombre d'occurrence
    for(o=0; o<nbDistinctChar; o++)
    {
        wprintf(L"%lc=",arrCharCount[o].valueChar);
        printf("%d ",arrCharCount[o].occ);
    }
    printf("\n");
}

int countDistinctChar(wchar_t *phrase)
{
    int j;
    int k=0;
    //on crée un tableau de taille suffisamment grande pour contenir les lettres et les lettres accentuées
    wchar_t distinctChar[50];
    //initialisation du tableau
    int o=0;
    for (o=0; o<wcslen(distinctChar); o++)
    {
        distinctChar[o]=L" ";
    }
    //nombre de lettres différentes à retourner
    int nbDistinctChar=0;

    int i=0;
    //on parcourt la phrase
    for(i=0; i<wcslen(phrase); i++)
    {
        // dejaCompt vaut 0 si on n'a pas déjà trouvé la lettre 1 si on l'a trouvé
        int dejaCompt = 0;
        j=0;
        if (iswalpha(phrase[i]))
        {
            //on parcourt le tableau des lettres jusqu'à trouver la lettre qui correspond ou arriver à la fin
            while((!dejaCompt)&& (j<nbDistinctChar))
            {
                //comparaison des lettres insensible à la case
                if(tolower(phrase[i])==distinctChar[j])
                {
                    // on a trouvé la même lettre
                    dejaCompt=1;
                }
                else
                {
                    //on a pas trouvé la même lettre on continue à parcourir le tableau de lettre
                    j++;
                }
            }
            //si on est arrivé à la fin c'est que la lettre n'était pas présente dans le tableau de lettre
            if(j==nbDistinctChar)
            {
                //on ajoute la lettre
                nbDistinctChar++;
                distinctChar[j]=phrase[i];
            }
        }
    }
    //on renvoie le nombre de lettres final
    return nbDistinctChar;
}

void countChar(wchar_t* phrase,struct coupleCharOcc *arrCharCount,int nbDistinctChar)
{
    int q=0;
    //initialisation des couples
    for (q =0; q<nbDistinctChar; q++)
    {
        arrCharCount[q].valueChar=NULL;
        arrCharCount[q].occ=0;
    }
    // itérateur de la phrase
    int k=0;
    //ittérateur du tableau de lettres
    int l=0;
    int trouve;
    for (k=0; k<wcslen(phrase); k++)
    {
        l=0;
        //on vérifie si le caractère est une lettre
        if (iswalpha(phrase[k]))
        {
            trouve=0;
            //tant que l'on a pas essayé toutes les lettres du tableau arrCharCount et qu'on n'a pas trouvé la bonne lettre
            while((arrCharCount[l].valueChar!=NULL)&& (!trouve))
            {
                //comparaison des lettres non sensible à la case
                if(tolower(phrase[k])==arrCharCount[l].valueChar)
                {
                    //la lettre a était trouvé
                    arrCharCount[l].occ=arrCharCount[l].occ+1;
                    trouve =1;
                }
                else
                {
                    l++;
                }
            }
            // on n'a pas trouvé la lettre dans le tableau de lettre
            if(arrCharCount[l].valueChar==NULL)
            {
                //on ajoute la nouvelle lettre au tableau
                arrCharCount[l].valueChar=tolower(phrase[k]);
                arrCharCount[l].occ=1;
            }
        }
    }
}

//fonction de comparaison des
int compareOccurence( const void* couple1, const void* couple2)
{
    struct  coupleCharOcc *c1= (struct coupleCharOcc *)couple1;
    struct  coupleCharOcc *c2= (struct coupleCharOcc *)couple2;
    if (c1->occ==c2->occ)
    {
        return 0;
    }
    else if(c1->occ < c2->occ)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// fonction de comparaison des lettres
int compareAlpha(const void* couple1, const void* couple2)
{
    struct  coupleCharOcc *c1= (struct coupleCharOcc *)couple1;
    struct  coupleCharOcc *c2= (struct coupleCharOcc *)couple2;
    //wcscoll retourne 0 si les deux lettres sont égales, 1 si la lettre de c1>c2 et -1 si la lettre de c1<c2
    return wcscoll(c1,c2);
}
