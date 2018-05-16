
#include <stdlib.h>
#include <stdio.h>

#include "ecos.h"
#include "problem.h"

#include <time.h>


pwork* solver_work;

int solution()
{

    gather_matrices();

    solver_work = ECOS_setup(
             82,  // number of vars
             74,  // number of inequality constrs
             60,  // p is number of equality constrs

             // l is positive orthant dimension
             // the first l elements of s are >= 0
             // in Gx + s = h
             40,
             // len(q), number of cones
             2,
             q,    // dimension of each cone
             0,    // number of exponential cones (UNSUPPORTED)
             Gpr,  // G coeffs  (CCS)
             Gjc,  // col_idx   (CCS)
             Gir,  // row_ptr   (CCS)
             Apr,  // A coeffs  (CCS)
             Ajc,  // col_idx   (CCS)
             Air,  // row_ptr   (CCS)
             c,   // obj coeffs
             h,  // Gx cone offsets
             b  // Ax offsets
    );

    if (solver_work != NULL){
        printf("About to solve \n");
    } else {
        printf("About to solve, but solver work is NULL \n");
    }


    return (int) ECOS_solve(solver_work);
}

void solution_cleanup(){
    ECOS_cleanup(solver_work, 0);
}

int main(){

    clock_t start = clock(), diff;
    

    // Below is for testing

    A[0][0] = 1.6243453636632417 ;
    A[0][1] = -0.6117564136500754 ;
    A[0][2] = -0.5281717522634557 ;
    A[0][3] = -1.0729686221561705 ;
    A[0][4] = 0.8654076293246785 ;
    A[0][5] = -2.3015386968802827 ;
    A[0][6] = 1.74481176421648 ;
    A[0][7] = -0.7612069008951028 ;
    A[0][8] = 0.31903909605709857 ;
    A[0][9] = -0.2493703754774101 ;
    A[0][10] = 1.462107937044974 ;
    A[0][11] = -2.060140709497654 ;
    A[0][12] = -0.3224172040135075 ;
    A[0][13] = -0.38405435466841564 ;
    A[0][14] = 1.1337694423354374 ;
    A[0][15] = -1.0998912673140309 ;
    A[0][16] = -0.17242820755043575 ;
    A[0][17] = -0.8778584179213718 ;
    A[0][18] = 0.04221374671559283 ;
    A[0][19] = 0.5828152137158222 ;
    b_[0][0] = -1.072964278711645 ;
    A[1][0] = -1.1006191772129212 ;
    A[1][1] = 1.1447237098396141 ;
    A[1][2] = 0.9015907205927955 ;
    A[1][3] = 0.5024943389018682 ;
    A[1][4] = 0.9008559492644118 ;
    A[1][5] = -0.6837278591743331 ;
    A[1][6] = -0.12289022551864817 ;
    A[1][7] = -0.9357694342590688 ;
    A[1][8] = -0.2678880796260159 ;
    A[1][9] = 0.530355466738186 ;
    A[1][10] = -0.691660751725309 ;
    A[1][11] = -0.39675352685597737 ;
    A[1][12] = -0.6871727001195994 ;
    A[1][13] = -0.8452056414987196 ;
    A[1][14] = -0.671246130836819 ;
    A[1][15] = -0.01266459891890136 ;
    A[1][16] = -1.1173103486352778 ;
    A[1][17] = 0.23441569781709215 ;
    A[1][18] = 1.6598021771098705 ;
    A[1][19] = 0.7420441605773356 ;
    b_[1][0] = 0.49515861120031657 ;
    A[2][0] = -0.19183555236161492 ;
    A[2][1] = -0.8876289640848363 ;
    A[2][2] = -0.7471582937508376 ;
    A[2][3] = 1.6924546010277466 ;
    A[2][4] = 0.05080775477602897 ;
    A[2][5] = -0.6369956465693534 ;
    A[2][6] = 0.19091548466746602 ;
    A[2][7] = 2.100255136478842 ;
    A[2][8] = 0.12015895248162915 ;
    A[2][9] = 0.6172031097074192 ;
    A[2][10] = 0.3001703199558275 ;
    A[2][11] = -0.35224984649351865 ;
    A[2][12] = -1.1425181980221402 ;
    A[2][13] = -0.3493427224128775 ;
    A[2][14] = -0.2088942333747781 ;
    A[2][15] = 0.5866231911821976 ;
    A[2][16] = 0.8389834138745049 ;
    A[2][17] = 0.9311020813035573 ;
    A[2][18] = 0.2855873252542588 ;
    A[2][19] = 0.8851411642707281 ;
    b_[2][0] = -0.952062100706259 ;
    A[3][0] = -0.7543979409966528 ;
    A[3][1] = 1.2528681552332879 ;
    A[3][2] = 0.5129298204180088 ;
    A[3][3] = -0.29809283510271567 ;
    A[3][4] = 0.48851814653749703 ;
    A[3][5] = -0.07557171302105573 ;
    A[3][6] = 1.131629387451427 ;
    A[3][7] = 1.5198168164221988 ;
    A[3][8] = 2.1855754065331614 ;
    A[3][9] = -1.3964963354881377 ;
    A[3][10] = -1.4441138054295894 ;
    A[3][11] = -0.5044658629464512 ;
    A[3][12] = 0.16003706944783047 ;
    A[3][13] = 0.8761689211162249 ;
    A[3][14] = 0.31563494724160523 ;
    A[3][15] = -2.022201215824003 ;
    A[3][16] = -0.3062040126283718 ;
    A[3][17] = 0.8279746426072462 ;
    A[3][18] = 0.2300947353643834 ;
    A[3][19] = 0.7620111803120247 ;
    b_[3][0] = -0.5181455523987548 ;
    A[4][0] = -0.22232814261035927 ;
    A[4][1] = -0.20075806892999745 ;
    A[4][2] = 0.1865613909882843 ;
    A[4][3] = 0.4100516472082563 ;
    A[4][4] = 0.19829972012676975 ;
    A[4][5] = 0.11900864580745882 ;
    A[4][6] = -0.6706622862890306 ;
    A[4][7] = 0.3775637863209194 ;
    A[4][8] = 0.12182127099143693 ;
    A[4][9] = 1.1294839079119197 ;
    A[4][10] = 1.198917879901507 ;
    A[4][11] = 0.18515641748394385 ;
    A[4][12] = -0.3752849500901142 ;
    A[4][13] = -0.6387304074542224 ;
    A[4][14] = 0.4234943540641129 ;
    A[4][15] = 0.07734006834855942 ;
    A[4][16] = -0.3438536755710756 ;
    A[4][17] = 0.04359685683424694 ;
    A[4][18] = -0.6200008439481293 ;
    A[4][19] = 0.6980320340722189 ;
    b_[4][0] = -1.4614036047221062 ;
    A[5][0] = -0.4471285647859982 ;
    A[5][1] = 1.2245077048054989 ;
    A[5][2] = 0.4034916417908 ;
    A[5][3] = 0.593578523237067 ;
    A[5][4] = -1.0949118457410418 ;
    A[5][5] = 0.1693824330586681 ;
    A[5][6] = 0.7405564510962748 ;
    A[5][7] = -0.9537006018079346 ;
    A[5][8] = -0.26621850600362207 ;
    A[5][9] = 0.03261454669335856 ;
    A[5][10] = -1.3731173202467557 ;
    A[5][11] = 0.31515939204229176 ;
    A[5][12] = 0.8461606475850334 ;
    A[5][13] = -0.8595159408319863 ;
    A[5][14] = 0.35054597866410736 ;
    A[5][15] = -1.3122834112374318 ;
    A[5][16] = -0.038695509266051115 ;
    A[5][17] = -1.6157723547032947 ;
    A[5][18] = 1.121417708235664 ;
    A[5][19] = 0.4089005379368278 ;
    b_[5][0] = -0.5163479086460222 ;
    A[6][0] = -0.024616955875778355 ;
    A[6][1] = -0.7751616191691596 ;
    A[6][2] = 1.2737559301587766 ;
    A[6][3] = 1.9671017492547347 ;
    A[6][4] = -1.857981864446752 ;
    A[6][5] = 1.2361640304528203 ;
    A[6][6] = 1.6276507531489064 ;
    A[6][7] = 0.3380116965744758 ;
    A[6][8] = -1.199268032335186 ;
    A[6][9] = 0.8633453175440216 ;
    A[6][10] = -0.18092030207815046 ;
    A[6][11] = -0.6039206277932573 ;
    A[6][12] = -1.2300581356669618 ;
    A[6][13] = 0.5505374959762154 ;
    A[6][14] = 0.7928068659193477 ;
    A[6][15] = -0.6235307296797916 ;
    A[6][16] = 0.5205763370733708 ;
    A[6][17] = -1.1443413896231427 ;
    A[6][18] = 0.8018610318713447 ;
    A[6][19] = 0.04656729842414554 ;
    b_[6][0] = 0.35111689651096534 ;
    A[7][0] = -0.18656977190734877 ;
    A[7][1] = -0.10174587252914521 ;
    A[7][2] = 0.8688861570058679 ;
    A[7][3] = 0.7504116398650081 ;
    A[7][4] = 0.5294653243527092 ;
    A[7][5] = 0.13770120999738608 ;
    A[7][6] = 0.07782112791270591 ;
    A[7][7] = 0.6183802619985245 ;
    A[7][8] = 0.23249455917873788 ;
    A[7][9] = 0.6825514068644851 ;
    A[7][10] = -0.31011677351806 ;
    A[7][11] = -2.434837764107139 ;
    A[7][12] = 1.038824601859414 ;
    A[7][13] = 2.1869796469742577 ;
    A[7][14] = 0.44136444356858207 ;
    A[7][15] = -0.10015523328349978 ;
    A[7][16] = -0.13644474389603303 ;
    A[7][17] = -0.11905418777480989 ;
    A[7][18] = 0.0174094083000046 ;
    A[7][19] = -1.1220187287468883 ;
    b_[7][0] = -0.06877046307863847 ;
    A[8][0] = -0.5170944579202279 ;
    A[8][1] = -0.997026827650263 ;
    A[8][2] = 0.2487991613877705 ;
    A[8][3] = -0.29664115237086275 ;
    A[8][4] = 0.4952113239779604 ;
    A[8][5] = -0.17470315974250095 ;
    A[8][6] = 0.9863351878212421 ;
    A[8][7] = 0.2135339013354418 ;
    A[8][8] = 2.1906997289697334 ;
    A[8][9] = -1.8963609228910925 ;
    A[8][10] = -0.646916688254908 ;
    A[8][11] = 0.901486891648711 ;
    A[8][12] = 2.528325706806398 ;
    A[8][13] = -0.24863477771546005 ;
    A[8][14] = 0.043668993178389105 ;
    A[8][15] = -0.22631424251360518 ;
    A[8][16] = 1.3314571125875918 ;
    A[8][17] = -0.2873078634760189 ;
    A[8][18] = 0.6800698398781045 ;
    A[8][19] = -0.3198015988986712 ;
    b_[8][0] = -1.3477649412536636 ;
    A[9][0] = -1.2725587552459943 ;
    A[9][1] = 0.31354772046343216 ;
    A[9][2] = 0.5031848134353261 ;
    A[9][3] = 1.2932258825322618 ;
    A[9][4] = -0.11044702641731631 ;
    A[9][5] = -0.6173620637123609 ;
    A[9][6] = 0.5627610966190263 ;
    A[9][7] = 0.24073709223773224 ;
    A[9][8] = 0.28066507712263905 ;
    A[9][9] = -0.07311270374727777 ;
    A[9][10] = 1.1603385699937696 ;
    A[9][11] = 0.36949271637572373 ;
    A[9][12] = 1.9046587083409812 ;
    A[9][13] = 1.1110566985605046 ;
    A[9][14] = 0.6590497961002102 ;
    A[9][15] = -1.6274383406162574 ;
    A[9][16] = 0.602319280295629 ;
    A[9][17] = 0.42028220364705954 ;
    A[9][18] = 0.8109516728035557 ;
    A[9][19] = 1.0444420947072588 ;
    b_[9][0] = 1.470739856691369 ;
    A[10][0] = -0.40087819178892664 ;
    A[10][1] = 0.8240056184504077 ;
    A[10][2] = -0.5623054310190898 ;
    A[10][3] = 1.9548780750090344 ;
    A[10][4] = -1.3319516665172482 ;
    A[10][5] = -1.7606885603987834 ;
    A[10][6] = -1.6507212658241002 ;
    A[10][7] = -0.8905555841630485 ;
    A[10][8] = -1.119115398559728 ;
    A[10][9] = 1.956078903703642 ;
    A[10][10] = -0.32649949807818424 ;
    A[10][11] = -1.342675789377436 ;
    A[10][12] = 1.114382976779792 ;
    A[10][13] = -0.5865239388215925 ;
    A[10][14] = -1.2368533765413974 ;
    A[10][15] = 0.8758389276492995 ;
    A[10][16] = 0.6233621765780327 ;
    A[10][17] = -0.4349566829552277 ;
    A[10][18] = 1.4075400002412286 ;
    A[10][19] = 0.12910157971072544 ;
    b_[10][0] = 0.33722093830845856 ;
    A[11][0] = 1.6169495988573002 ;
    A[11][1] = 0.5027408819999043 ;
    A[11][2] = 1.5588055406198593 ;
    A[11][3] = 0.10940269642542817 ;
    A[11][4] = -1.2197443969790327 ;
    A[11][5] = 2.4493686490613973 ;
    A[11][6] = -0.5457741679825677 ;
    A[11][7] = -0.19883786288889674 ;
    A[11][8] = -0.7003985049212547 ;
    A[11][9] = -0.20339444896455844 ;
    A[11][10] = 0.24266944108179458 ;
    A[11][11] = 0.20183017887400403 ;
    A[11][12] = 0.6610202875986929 ;
    A[11][13] = 1.792158208975567 ;
    A[11][14] = -0.12046457178850745 ;
    A[11][15] = -1.2331207354464266 ;
    A[11][16] = -1.1823181265096336 ;
    A[11][17] = -0.6657545181991266 ;
    A[11][18] = -1.674195807618932 ;
    A[11][19] = 0.8250298244389859 ;
    b_[11][0] = 1.0080654330757632 ;
    A[12][0] = -0.4982135636310781 ;
    A[12][1] = -0.3109849783028509 ;
    A[12][2] = -0.0018914828380037015 ;
    A[12][3] = -1.396620424595432 ;
    A[12][4] = -0.861316360776042 ;
    A[12][5] = 0.6747115256879723 ;
    A[12][6] = 0.6185391307862932 ;
    A[12][7] = -0.44317193070063776 ;
    A[12][8] = 1.8105349141254563 ;
    A[12][9] = -1.3057269225577375 ;
    A[12][10] = -0.34498721015497946 ;
    A[12][11] = -0.23083974313546946 ;
    A[12][12] = -2.79308500014654 ;
    A[12][13] = 1.9375288136160798 ;
    A[12][14] = 0.36633201454005826 ;
    A[12][15] = -1.0445893819077916 ;
    A[12][16] = 2.0511734428574444 ;
    A[12][17] = 0.5856620001723825 ;
    A[12][18] = 0.4295261400219645 ;
    A[12][19] = -0.6069983982000461 ;
    b_[12][0] = 0.7852269196346882 ;
    A[13][0] = 0.1062227240352178 ;
    A[13][1] = -1.5256803162293577 ;
    A[13][2] = 0.7950260944248447 ;
    A[13][3] = -0.37443831884322065 ;
    A[13][4] = 0.13404819655462313 ;
    A[13][5] = 1.2020548621997058 ;
    A[13][6] = 0.28474811084905793 ;
    A[13][7] = 0.2624674454632686 ;
    A[13][8] = 0.27649930482218366 ;
    A[13][9] = -0.7332716038953129 ;
    A[13][10] = 0.8360047194342688 ;
    A[13][11] = 1.5433591108044837 ;
    A[13][12] = 0.7588056600979309 ;
    A[13][13] = 0.8849088144648833 ;
    A[13][14] = -0.8772815189181883 ;
    A[13][15] = -0.8677872228729256 ;
    A[13][16] = -1.44087602429184 ;
    A[13][17] = 1.232253070828436 ;
    A[13][18] = -0.2541798676073683 ;
    A[13][19] = 1.3998439424809859 ;
    b_[13][0] = -0.6648677669672133 ;
    A[14][0] = -0.7819116826868007 ;
    A[14][1] = -0.437508982828581 ;
    A[14][2] = 0.0954250871912577 ;
    A[14][3] = 0.9214500686595114 ;
    A[14][4] = 0.060750195799506745 ;
    A[14][5] = 0.21112475500771674 ;
    A[14][6] = 0.01652756730561561 ;
    A[14][7] = 0.17718772027596041 ;
    A[14][8] = -1.1164700178847444 ;
    A[14][9] = 0.0809271009732786 ;
    A[14][10] = -0.18657899351146628 ;
    A[14][11] = -0.0568244808858473 ;
    A[14][12] = 0.4923365559366488 ;
    A[14][13] = -0.6806781410088858 ;
    A[14][14] = -0.0845080274046298 ;
    A[14][15] = -0.2973618827735036 ;
    A[14][16] = 0.41730200497486253 ;
    A[14][17] = 0.7847706510155895 ;
    A[14][18] = -0.9554252623736892 ;
    A[14][19] = 0.5859104311026156 ;
    b_[14][0] = -1.9450469586120391 ;
    A[15][0] = 2.0657833202188343 ;
    A[15][1] = -1.471156925832625 ;
    A[15][2] = -0.8301718953151139 ;
    A[15][3] = -0.8805775998441709 ;
    A[15][4] = -0.27909772154329027 ;
    A[15][5] = 1.622849085954001 ;
    A[15][6] = 0.013352676347176594 ;
    A[15][7] = -0.6946935952872263 ;
    A[15][8] = 0.6218035043055724 ;
    A[15][9] = -0.5998045310708474 ;
    A[15][10] = 1.1234121620219353 ;
    A[15][11] = 0.30526704024401075 ;
    A[15][12] = 1.3887793963702684 ;
    A[15][13] = -0.6613442431530187 ;
    A[15][14] = 3.0308571123720305 ;
    A[15][15] = 0.8245846250334574 ;
    A[15][16] = 0.6545801525867004 ;
    A[15][17] = -0.05118844760766421 ;
    A[15][18] = -0.7255971191344275 ;
    A[15][19] = -0.8677686776235903 ;
    b_[15][0] = -0.9154243682317061 ;
    A[16][0] = -0.13597732610058932 ;
    A[16][1] = -0.7972697854931297 ;
    A[16][2] = 0.28267571224842025 ;
    A[16][3] = -0.8260974318473202 ;
    A[16][4] = 0.6210827008390084 ;
    A[16][5] = 0.9561217041246964 ;
    A[16][6] = -0.7058405074022839 ;
    A[16][7] = 1.1926860677546935 ;
    A[16][8] = -0.23794193575218264 ;
    A[16][9] = 1.1552878860882252 ;
    A[16][10] = 0.4381663472912375 ;
    A[16][11] = 1.1223283216570923 ;
    A[16][12] = -0.9970197955296825 ;
    A[16][13] = -0.10679398677922511 ;
    A[16][14] = 1.4514292605909354 ;
    A[16][15] = -0.6180368476815788 ;
    A[16][16] = -2.037201225680795 ;
    A[16][17] = -1.9425891814764555 ;
    A[16][18] = -2.506440652676061 ;
    A[16][19] = -2.114163921916826 ;
    b_[16][0] = 1.2251558492732308 ;
    A[17][0] = -0.41163916318848254 ;
    A[17][1] = 1.2785280828417218 ;
    A[17][2] = -0.4422292795131728 ;
    A[17][3] = 0.3235273536014321 ;
    A[17][4] = -0.10999149016360682 ;
    A[17][5] = 0.008548945436024693 ;
    A[17][6] = -0.16819883974471597 ;
    A[17][7] = -0.1741803443079907 ;
    A[17][8] = 0.46116409997701746 ;
    A[17][9] = -1.1759826714413153 ;
    A[17][10] = 1.0101271773347245 ;
    A[17][11] = 0.9200179332477632 ;
    A[17][12] = -0.19505734087590118 ;
    A[17][13] = 0.8053934242321815 ;
    A[17][14] = -0.7013444262571769 ;
    A[17][15] = -0.5372230238753384 ;
    A[17][16] = 0.15626385027008327 ;
    A[17][17] = -0.1902210250848615 ;
    A[17][18] = -0.44873803267162277 ;
    A[17][19] = -0.6724480387865963 ;
    b_[17][0] = -1.053546073700315 ;
    A[18][0] = -0.5574947217860433 ;
    A[18][1] = 0.9391687441964878 ;
    A[18][2] = -1.9433234056683528 ;
    A[18][3] = 0.352494364369333 ;
    A[18][4] = -0.2364369518129867 ;
    A[18][5] = 0.7278134999996488 ;
    A[18][6] = 0.5150736136393657 ;
    A[18][7] = -2.7825344676529227 ;
    A[18][8] = 0.5846466104774262 ;
    A[18][9] = 0.32427424344842104 ;
    A[18][10] = 0.02186283662655242 ;
    A[18][11] = -0.46867381627789134 ;
    A[18][12] = 0.8532812219556223 ;
    A[18][13] = -0.4130293097110322 ;
    A[18][14] = 1.8347176266496867 ;
    A[18][15] = 0.5643828554943137 ;
    A[18][16] = 2.1378280674394823 ;
    A[18][17] = -0.7855339969202355 ;
    A[18][18] = -1.7559256402328518 ;
    A[18][19] = 0.7147895974858154 ;
    b_[18][0] = 0.8160436843240609 ;
    A[19][0] = 0.8527040617252863 ;
    A[19][1] = 0.03536009705475734 ;
    A[19][2] = -1.5387932457446432 ;
    A[19][3] = -0.4478951847161186 ;
    A[19][4] = 0.6179855339203347 ;
    A[19][5] = -0.18417632565374534 ;
    A[19][6] = -0.11598518547239624 ;
    A[19][7] = -0.1754589686617526 ;
    A[19][8] = -0.9339146556265013 ;
    A[19][9] = -0.5330203260835993 ;
    A[19][10] = -1.426555420520532 ;
    A[19][11] = 1.7679599483110264 ;
    A[19][12] = -0.4753728751379821 ;
    A[19][13] = 0.47761018181755727 ;
    A[19][14] = -1.0218859446413093 ;
    A[19][15] = 0.7945282396010823 ;
    A[19][16] = -1.8731609776353015 ;
    A[19][17] = 0.9206151180549562 ;
    A[19][18] = -0.03536792487871091 ;
    A[19][19] = 2.1106050536007097 ;
    b_[19][0] = -0.6124069731288238 ;
    A[20][0] = -1.3065340728440185 ;
    A[20][1] = 0.076380480159592 ;
    A[20][2] = 0.3672318138838647 ;
    A[20][3] = 1.2328991923762371 ;
    A[20][4] = -0.4228569613907754 ;
    A[20][5] = 0.08646440652428741 ;
    A[20][6] = -2.1424667290773685 ;
    A[20][7] = -0.830168864022708 ;
    A[20][8] = 0.45161595055524156 ;
    A[20][9] = 1.1041743263032135 ;
    A[20][10] = -0.28173626906561283 ;
    A[20][11] = 2.0563555231982935 ;
    A[20][12] = 1.7602492264490932 ;
    A[20][13] = -0.06065249177480989 ;
    A[20][14] = -2.4135030011737877 ;
    A[20][15] = -1.7775663758059874 ;
    A[20][16] = -0.7778588266274128 ;
    A[20][17] = 1.1158411079241686 ;
    A[20][18] = 0.3102722877837673 ;
    A[20][19] = -2.094247816222812 ;
    b_[20][0] = 0.3931092448539835 ;
    A[21][0] = -0.22876582887016242 ;
    A[21][1] = 1.6133613745631155 ;
    A[21][2] = -0.3748046873026527 ;
    A[21][3] = -0.7499696172756662 ;
    A[21][4] = 2.054624102518116 ;
    A[21][5] = 0.05340953679834792 ;
    A[21][6] = -0.4791570987860799 ;
    A[21][7] = 0.3501671588282789 ;
    A[21][8] = 0.017164726374088564 ;
    A[21][9] = -0.42914227823509377 ;
    A[21][10] = 1.208456328551963 ;
    A[21][11] = 1.1157018027844863 ;
    A[21][12] = 0.8408615581411037 ;
    A[21][13] = -0.1028872175735376 ;
    A[21][14] = 1.146900376399483 ;
    A[21][15] = -0.04970257915867584 ;
    A[21][16] = 0.46664326722884075 ;
    A[21][17] = 1.033686867939501 ;
    A[21][18] = 0.8088443602656821 ;
    A[21][19] = 1.7897546832062712 ;
    b_[21][0] = -1.8239198526251938 ;
    A[22][0] = 0.4512840160401709 ;
    A[22][1] = -1.6840599858682372 ;
    A[22][2] = -1.1601701049822761 ;
    A[22][3] = 1.350106818681726 ;
    A[22][4] = -0.3312831699326283 ;
    A[22][5] = 0.3865391451330911 ;
    A[22][6] = -0.8514556565308268 ;
    A[22][7] = 1.000881423680301 ;
    A[22][8] = -0.38483224883279044 ;
    A[22][9] = 1.4581082386095199 ;
    A[22][10] = -0.5322340208981775 ;
    A[22][11] = 1.1181333967176956 ;
    A[22][12] = 0.6743961048208689 ;
    A[22][13] = -0.7223919054141509 ;
    A[22][14] = 1.0989963327471792 ;
    A[22][15] = -0.901634490475998 ;
    A[22][16] = -0.8224671889042517 ;
    A[22][17] = 0.7217112921126926 ;
    A[22][18] = -0.625342001465988 ;
    A[22][19] = -0.5938430672545096 ;
    b_[22][0] = 1.167075165999964 ;
    A[23][0] = -0.3439007092103924 ;
    A[23][1] = -1.0001691898725158 ;
    A[23][2] = 1.0449944096738975 ;
    A[23][3] = 0.6085146984848496 ;
    A[23][4] = -0.06932869669048287 ;
    A[23][5] = -0.10839206717353982 ;
    A[23][6] = 0.45015551276717897 ;
    A[23][7] = 1.7653351005190716 ;
    A[23][8] = 0.8709698025322423 ;
    A[23][9] = -0.5084571342754007 ;
    A[23][10] = 0.7774192052488628 ;
    A[23][11] = -0.11877117210308928 ;
    A[23][12] = -0.19899818380372442 ;
    A[23][13] = 1.8664713751521251 ;
    A[23][14] = -0.41893789767812306 ;
    A[23][15] = -0.47918491512740585 ;
    A[23][16] = -1.9521052872452325 ;
    A[23][17] = -1.4023291454531368 ;
    A[23][18] = 0.4511229387345986 ;
    A[23][19] = -0.6949209011852391 ;
    b_[23][0] = -0.03966870009048212 ;
    A[24][0] = 0.515413801783241 ;
    A[24][1] = -1.1148710523659369 ;
    A[24][2] = -0.7673098263317347 ;
    A[24][3] = 0.6745707069560037 ;
    A[24][4] = 1.460892380463078 ;
    A[24][5] = 0.5924728014240198 ;
    A[24][6] = 1.197830841721251 ;
    A[24][7] = 1.7045941713724069 ;
    A[24][8] = 1.0400891531540952 ;
    A[24][9] = -0.918440038300026 ;
    A[24][10] = -0.10534471250754213 ;
    A[24][11] = 0.630195670684911 ;
    A[24][12] = -0.4148469012882354 ;
    A[24][13] = 0.45194603732122307 ;
    A[24][14] = -1.5791562853944654 ;
    A[24][15] = -0.8286279788564058 ;
    A[24][16] = 0.528879745585174 ;
    A[24][17] = -2.2370865111124707 ;
    A[24][18] = -1.1077125022845524 ;
    A[24][19] = -0.01771831791014226 ;
    b_[24][0] = 0.8858257989659072 ;
    A[25][0] = -1.719394474619523 ;
    A[25][1] = 0.057120996082092076 ;
    A[25][2] = -0.7995474906917599 ;
    A[25][3] = -0.2915945955008327 ;
    A[25][4] = -0.25898285340053234 ;
    A[25][5] = 0.1892931975586576 ;
    A[25][6] = -0.5637887345823027 ;
    A[25][7] = 0.08968640732259017 ;
    A[25][8] = -0.6011568006493835 ;
    A[25][9] = 0.5560735100773853 ;
    A[25][10] = 1.693809113288081 ;
    A[25][11] = 0.19686977925029145 ;
    A[25][12] = 0.1698692553475717 ;
    A[25][13] = -1.1640079711612021 ;
    A[25][14] = 0.6933662256603845 ;
    A[25][15] = -0.7580673285562323 ;
    A[25][16] = -0.8088471964721285 ;
    A[25][17] = 0.5574394528580334 ;
    A[25][18] = 0.18103874435787085 ;
    A[25][19] = 1.1071754509490623 ;
    b_[25][0] = 0.18986164938309566 ;
    A[26][0] = 1.4428769284963092 ;
    A[26][1] = -0.5396815622024924 ;
    A[26][2] = 0.12837699015594436 ;
    A[26][3] = 1.7604151835753223 ;
    A[26][4] = 0.9665392502290573 ;
    A[26][5] = 0.7130490503032691 ;
    A[26][6] = 1.3062060651354486 ;
    A[26][7] = -0.604602969164376 ;
    A[26][8] = 0.6365834094146309 ;
    A[26][9] = 1.4092533893640082 ;
    A[26][10] = 1.6209122856217475 ;
    A[26][11] = -0.8061848173822241 ;
    A[26][12] = -0.2516742076314244 ;
    A[26][13] = 0.3827151737243639 ;
    A[26][14] = -0.2889973430098159 ;
    A[26][15] = -0.3918162398080484 ;
    A[26][16] = 0.684001328181953 ;
    A[26][17] = -0.35340998286701436 ;
    A[26][18] = -1.7879128911997157 ;
    A[26][19] = 0.36184731583956825 ;
    b_[26][0] = 0.7980637952989431 ;
    A[27][0] = -0.4244927905709274 ;
    A[27][1] = -0.7315309817303334 ;
    A[27][2] = -1.5657381506559054 ;
    A[27][3] = 1.0138224669717055 ;
    A[27][4] = -2.2271126318500145 ;
    A[27][5] = -1.6993336047222958 ;
    A[27][6] = -0.27584606256114336 ;
    A[27][7] = 1.2289555856506973 ;
    A[27][8] = 1.3097059056826534 ;
    A[27][9] = -1.1549826349293644 ;
    A[27][10] = -0.17763219598355098 ;
    A[27][11] = -1.5104563750875688 ;
    A[27][12] = 1.0112070637749084 ;
    A[27][13] = -1.4765626605201803 ;
    A[27][14] = -0.14319574500723764 ;
    A[27][15] = 1.0329837789497511 ;
    A[27][16] = -0.22241402852990858 ;
    A[27][17] = 1.4701603438257402 ;
    A[27][18] = -0.870008223190852 ;
    A[27][19] = 0.36919046954687373 ;
    b_[27][0] = -0.10193203926360005 ;
    A[28][0] = 0.8532821858237332 ;
    A[28][1] = -0.13971173044107246 ;
    A[28][2] = 1.3863142642463189 ;
    A[28][3] = 0.5481295846881931 ;
    A[28][4] = -1.6374495930083417 ;
    A[28][5] = 3.9586027040379634 ;
    A[28][6] = 0.6486436440906672 ;
    A[28][7] = 0.10734329382358966 ;
    A[28][8] = -1.3988128186664763 ;
    A[28][9] = 0.08176781880561644 ;
    A[28][10] = -0.45994283084068716 ;
    A[28][11] = 0.6443536660303223 ;
    A[28][12] = 0.37167029121186534 ;
    A[28][13] = 1.853009485069379 ;
    A[28][14] = 0.14225137252631778 ;
    A[28][15] = 0.5135054799885475 ;
    A[28][16] = 0.3724568515114425 ;
    A[28][17] = -0.14848980305939366 ;
    A[28][18] = -0.1834001973200239 ;
    A[28][19] = 1.1010002026684818 ;
    b_[28][0] = 0.7433565435138623 ;
    A[29][0] = 0.7800271353386294 ;
    A[29][1] = -0.62944160405378 ;
    A[29][2] = -1.1134361029729902 ;
    A[29][3] = -0.06741002494685439 ;
    A[29][4] = 1.1614399816743937 ;
    A[29][5] = -0.027529386267978004 ;
    A[29][6] = 1.7464350892279725 ;
    A[29][7] = -0.7750702870734348 ;
    A[29][8] = 0.14164053766580517 ;
    A[29][9] = -2.516303860965749 ;
    A[29][10] = -0.5956678809102903 ;
    A[29][11] = -0.30912131864186215 ;
    A[29][12] = 0.5109377744920892 ;
    A[29][13] = 1.7106618386711354 ;
    A[29][14] = 0.03494358936374005 ;
    A[29][15] = 1.4539175816088175 ;
    A[29][16] = 0.6616810764659825 ;
    A[29][17] = 0.9863521802120643 ;
    A[29][18] = -0.466154856825928 ;
    A[29][19] = 1.3849913436486387 ;
    b_[29][0] = -1.5095726842240433 ;

    int exit_code = solution();

    diff = clock() - start;
    double milliseconds = (float) diff * 1000 / CLOCKS_PER_SEC;
    printf("%d solution in %f milliseconds \n", exit_code, milliseconds);

    printf("Solution was:\n");

    
    printf(" sym0 : %f \n", solver_work->x[0]);
    printf(" sym1 : %f \n", solver_work->x[1]);
    printf(" sym2[0][0] : %f \n", solver_work->x[2]);
    printf(" x[0][0] : %f \n", solver_work->x[3]);
    printf(" x[1][0] : %f \n", solver_work->x[4]);
    printf(" x[2][0] : %f \n", solver_work->x[5]);
    printf(" x[3][0] : %f \n", solver_work->x[6]);
    printf(" x[4][0] : %f \n", solver_work->x[7]);
    printf(" x[5][0] : %f \n", solver_work->x[8]);
    printf(" x[6][0] : %f \n", solver_work->x[9]);
    printf(" x[7][0] : %f \n", solver_work->x[10]);
    printf(" x[8][0] : %f \n", solver_work->x[11]);
    printf(" x[9][0] : %f \n", solver_work->x[12]);
    printf(" x[10][0] : %f \n", solver_work->x[13]);
    printf(" x[11][0] : %f \n", solver_work->x[14]);
    printf(" x[12][0] : %f \n", solver_work->x[15]);
    printf(" x[13][0] : %f \n", solver_work->x[16]);
    printf(" x[14][0] : %f \n", solver_work->x[17]);
    printf(" x[15][0] : %f \n", solver_work->x[18]);
    printf(" x[16][0] : %f \n", solver_work->x[19]);
    printf(" x[17][0] : %f \n", solver_work->x[20]);
    printf(" x[18][0] : %f \n", solver_work->x[21]);
    printf(" x[19][0] : %f \n", solver_work->x[22]);
    printf(" sym2[1][0] : %f \n", solver_work->x[23]);
    printf(" sym2[2][0] : %f \n", solver_work->x[24]);
    printf(" sym2[3][0] : %f \n", solver_work->x[25]);
    printf(" sym2[4][0] : %f \n", solver_work->x[26]);
    printf(" sym2[5][0] : %f \n", solver_work->x[27]);
    printf(" sym2[6][0] : %f \n", solver_work->x[28]);
    printf(" sym2[7][0] : %f \n", solver_work->x[29]);
    printf(" sym2[8][0] : %f \n", solver_work->x[30]);
    printf(" sym2[9][0] : %f \n", solver_work->x[31]);
    printf(" sym2[10][0] : %f \n", solver_work->x[32]);
    printf(" sym2[11][0] : %f \n", solver_work->x[33]);
    printf(" sym2[12][0] : %f \n", solver_work->x[34]);
    printf(" sym2[13][0] : %f \n", solver_work->x[35]);
    printf(" sym2[14][0] : %f \n", solver_work->x[36]);
    printf(" sym2[15][0] : %f \n", solver_work->x[37]);
    printf(" sym2[16][0] : %f \n", solver_work->x[38]);
    printf(" sym2[17][0] : %f \n", solver_work->x[39]);
    printf(" sym2[18][0] : %f \n", solver_work->x[40]);
    printf(" sym2[19][0] : %f \n", solver_work->x[41]);
    printf(" sym2[20][0] : %f \n", solver_work->x[42]);
    printf(" sym2[21][0] : %f \n", solver_work->x[43]);
    printf(" sym2[22][0] : %f \n", solver_work->x[44]);
    printf(" sym2[23][0] : %f \n", solver_work->x[45]);
    printf(" sym2[24][0] : %f \n", solver_work->x[46]);
    printf(" sym2[25][0] : %f \n", solver_work->x[47]);
    printf(" sym2[26][0] : %f \n", solver_work->x[48]);
    printf(" sym2[27][0] : %f \n", solver_work->x[49]);
    printf(" sym2[28][0] : %f \n", solver_work->x[50]);
    printf(" sym2[29][0] : %f \n", solver_work->x[51]);
    printf(" sym3[0][0] : %f \n", solver_work->x[52]);
    printf(" sym3[1][0] : %f \n", solver_work->x[53]);
    printf(" sym3[2][0] : %f \n", solver_work->x[54]);
    printf(" sym3[3][0] : %f \n", solver_work->x[55]);
    printf(" sym3[4][0] : %f \n", solver_work->x[56]);
    printf(" sym3[5][0] : %f \n", solver_work->x[57]);
    printf(" sym3[6][0] : %f \n", solver_work->x[58]);
    printf(" sym3[7][0] : %f \n", solver_work->x[59]);
    printf(" sym3[8][0] : %f \n", solver_work->x[60]);
    printf(" sym3[9][0] : %f \n", solver_work->x[61]);
    printf(" sym3[10][0] : %f \n", solver_work->x[62]);
    printf(" sym3[11][0] : %f \n", solver_work->x[63]);
    printf(" sym3[12][0] : %f \n", solver_work->x[64]);
    printf(" sym3[13][0] : %f \n", solver_work->x[65]);
    printf(" sym3[14][0] : %f \n", solver_work->x[66]);
    printf(" sym3[15][0] : %f \n", solver_work->x[67]);
    printf(" sym3[16][0] : %f \n", solver_work->x[68]);
    printf(" sym3[17][0] : %f \n", solver_work->x[69]);
    printf(" sym3[18][0] : %f \n", solver_work->x[70]);
    printf(" sym3[19][0] : %f \n", solver_work->x[71]);
    printf(" sym3[20][0] : %f \n", solver_work->x[72]);
    printf(" sym3[21][0] : %f \n", solver_work->x[73]);
    printf(" sym3[22][0] : %f \n", solver_work->x[74]);
    printf(" sym3[23][0] : %f \n", solver_work->x[75]);
    printf(" sym3[24][0] : %f \n", solver_work->x[76]);
    printf(" sym3[25][0] : %f \n", solver_work->x[77]);
    printf(" sym3[26][0] : %f \n", solver_work->x[78]);
    printf(" sym3[27][0] : %f \n", solver_work->x[79]);
    printf(" sym3[28][0] : %f \n", solver_work->x[80]);
    printf(" sym3[29][0] : %f \n", solver_work->x[81]);

    solution_cleanup();

}