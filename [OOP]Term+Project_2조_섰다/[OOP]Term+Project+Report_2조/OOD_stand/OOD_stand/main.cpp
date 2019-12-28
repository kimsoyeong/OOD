#include"pch.h"
#include "cardDeck.h"
#include "player.h"
#include "computer.h"
#include<iostream>
#include<string>
#include<vector>
#include<random>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

// 함수 선언
void gameResult(player *arr[], cardDeck& carddeck, int n); // 게임을 수행하는 함수
int* Winner(int *score, player* arr[], int n); // 승자를 가려내는 함수
void printPae(int i, int j); // 화투 패 그림을 출력하는 함수
vector<string> Split(string str, char delimiter); // split 함수
void start();

// 전역 변수
int money; // 판돈
vector<int> pandon; //판돈 배열_게임 중 베팅한 금액을 순서대로 저장

int main() {
	cardDeck cd; //카드 집

	start();
	int n = 0; // npc를 포함한 전체 player 수
	cout << "PLAYER 수를 선택하세요.";
	while (n > 4 || n < 2) {
		cout << " 2~4명중 입력하세요." << endl;
		cin >> n;
		if (n <= 4 && n >= 2) {
			break;
		}
	}
	
	// 판돈 선택
	while (1) {
		cout << "판돈을 선택하세요. 선택한 판돈의 50배가 기본 잔고로 지급됩니다." << endl;
		cout << "1) 20원\n2) 200원\n3) 2000원\n--> 금액을 입력하세요. <--" << endl;
		cin >> money;

		if (money == 20 || money == 200 || money == 2000) {
			money = money * 5;
			break;
		}
	}

	player * p[4]{ NULL }; //player객체 배열 생성
	player * tmp[4]{ NULL }; //player임시 객체 배열 생성

	p[0] = new player(); // 사용자 player 객체
	p[0]->setMoney(money * 10); // 잔고 지급
	for (int i = 1; i < n; i++) {
		p[i] = new computer(); // computer 객체 생성
		p[i]->setMoney(money * 10);
	}

	int start = 1;
	int count;
	while (start) {
		cout << "\n'시작 = 아무 숫자, 나가기 = 0' 을 입력하세요." << endl;
		cin >> start;
		count = 0;
		for (int i = 0, j = 0; i < n; i++) {
			if (p[i]->getMoney() < money) {
				cout << "한 명의 Player의 잔고가 부족하여 죽었습니다." << endl;
			}
			else {
				count++;
				tmp[j++] = p[i];
			}
		}
		n = count;
		if (p[0]->getMoney() < money) { // 잔고 부족인 경우, 게임 종료
			cout << "당신의 잔고가 부족하여 게임에 입장할 수 없습니다." << endl;
			break;
		}
		else {
			if (n > 1) {
				cd.cd_shuffle();
				// 함수: 두 장의 패를 뽑아 각자 점수를 미리 계산해둠
				for (int i = 0; i < n; i++) {
					tmp[i]->getCard(cd);
				}

				if (start != 0) {
					system("cls"); // 새로 출력
					cout << "당신의 패 : " << tmp[0]->getPae1() << " " << tmp[0]->getPae2() << endl;
					int c = tmp[0]->getPae1();
					int b = tmp[0]->getPae2();
					printPae(c, b);

					gameResult(tmp, cd, n); //게임
				}
			}
			else {
				cout << "\n!!PLAYER 0 WIN!!" << endl;
				break;
			}
		}
	}

	cout << ">>>>>>>게임 결과<<<<<<<" << endl;
	cout << "Player의 현재 잔고는 " << tmp[0]->getMoney() << "원 입니다." << endl;
	system("pause");
}

// 한 판의 게임을 진행하는 함수
void gameResult(player *arr[], cardDeck& carddeck, int n) {
	for (int i = 0; i < n; i++) {
		arr[i]->setMoney(arr[i]->getMoney() - (money/5));
		pandon.push_back((money / 5));
	}
	int pd = 0;
	for (int i = 0; i < pandon.size(); i++) {
		pd += pandon[i]; // 깔린 돈 계산
	}
	cout << "\n-------현재 판돈: " << pd << "원-------\n" << endl;

	for (int i = 0; i < n; i++) {
		int bet = arr[i]->betting_type(i);
		pd = arr[i]->betting(bet, pandon, money);
		cout << "-------현재 판돈: " << pd << "원-------\n" << endl;
	}

	int score[4];
	for (int i = 0; i < n; i++) {
		score[i] = arr[i]->getScore();
	}

	int* winnerindex = Winner(score, arr, n); // 동점자 인덱스 배열

	int cnt = 0; //동점자 수
	for (int i = 0; i < n; i++) {
		if (winnerindex[i] > -1) {
			cnt++;
		}
	}

	int tt[4]; // 포인터 변수 손실 방지 복사 배열
	for (int i = 0; i < n; i++) {
		tt[i] = winnerindex[i];
	}
	int temp = winnerindex[0];
	if (cnt > 1) { // 동점자 존재하는 경우
		for (int i = 0; i < n; i++) {
			int wi = tt[i];
			if (wi > -1) {
				arr[wi]->setMoney(arr[wi]->getMoney() + (pd / cnt)); //잔고에 판돈이 더해짐
				cout << "\nPlayer " << wi << " Draw!!!" << endl;
			}
		}
	}
	else { // 동점자 존재X인 경우
		arr[temp]->setMoney(arr[temp]->getMoney() + pd); //잔고에 판돈이 더해짐
		cout << "\nPlayer " << temp << " Win!!!\n" << endl;
	}

	// 패 공개
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Player " << i << "'s 패 :";
		if (arr[i]->getPae1() == -1) {
			cout << " DIE" << endl;
		}
		else {
			cout << arr[i]->getPae1() << " " << arr[i]->getPae2();
			arr[i]->print_jokbo();
			printPae(arr[i]->getPae1(), arr[i]->getPae2());
			cout << endl;
		}
	}

	Sleep(1500);
	cout << endl;
	// 유저들의 잔고 공개
	for (int i = 0; i < n; i++) {
		cout << "Player" << i << "'s Money = " << arr[i]->getMoney() << endl;
	}

	carddeck.init(); // 카드덱을 초기화
	pandon.clear();    // 판돈을 초기화
	Sleep(1000); //1초 대기
}

// 승자 결정 메소드
int* Winner(int *score, player* arr[], int n) {
	int max = score[0]; //가장 큰 점수
	int agent = -1; //암행어사
	bool s1 = false; // 암행어사 작동 여부
	int thangjabi = -1; //땡잡이
	bool s2 = false; // 땡잡이 작동 여부

	int drawindex[4]{ -1,-1,-1,-1 }; //동점자 배열

	for (int i = 0; i < n; i++) {
		int s = score[i];
		int a = arr[i]->getPae1();
		int b = arr[i]->getPae2();

		// 특수족보 확인_동시에 생기는 경우는 없음
		if (score[i] == 1) {
			if ((a == 4 && b == 7) || (a == 7 && b == 4)) { // 암행어사 족보 확인
				agent = i;
			}
		}
		else if(score[i] == 0) {
			if ((a == 3 && b == 7) || (b == 3 && a == 7)) { // 땡잡이 족보 확인
				thangjabi = i;
			}
		}

		// 특수족보가 이기는 족보의 존재 여부 확인
		if (score[i] == 27 || score[i] == 28) {
			s1 = true;
		}
		if (score[i] >= 16 && score[i] <= 25) {
			s2 = true;
		}

		// 특수족보 작동
		if (s1 == true && agent != -1) {
			score[agent] = 29;
		}
		if (s2 == true && thangjabi != -1) {
			score[thangjabi] = 25;
		}
	}

	for (int i = 0; i < n; i++) {
		// 족보별 점수 계산
		if (max < score[i]) {
			arr[i]->setScore(score[i]);
			max = score[i];
		}
	}

	for (int i = 0, j = 0; i < n; i++) {
		if (max == score[i]) {	//동점인 경우,
			drawindex[j++] = i;	//모든 동점자의 인덱스를 받음
		}
	}

	return drawindex;
}

// 화투 패 그림을 출력하는 함수
void printPae(int i, int j) {
	string cards[] = {
   " B;::;;;;;:;:::::::::::::7\n X B5..,.,.:BMOgODOgDDOBQ\n S Q,       ppUwU12121wPQ\n X B:       ;QHU12Jw1wJKR\n S M,,6UJHK7.,ROX2UwU11KR\n a Q:LsZ:.     sDME6XX5GM\n S R: 7          :c1wwsJB\n a B.,g              ,  D\n S Q..g             U6BRD\n  X B. s;           sBBBBg\n 5 M ,2Z:......   JPBBBBO\n X R, :. 7;..:,., LBQBBBG\n 5 pBr ::;rrs::rBR5BBQBBD\n a XBBL  .:r.,RBQBZBBBBBE\n S UBBB:   JSwBBOrBBBBBBD\n X UBBBDcJ .EsX::wBBBBBBG\n S 2BBBBBQr i.wrBMHLrwBBD\n X UBBBBBBc7 ..BBs7  wsBg\n p r7rrr7v7rv;v7Lss7LJ27s\n",
   "rr;ii77vrr;r;r;i;i;rr;\nXBODBS    ;apGgORDOZGB5\nPr               :;r;pX\nD.   77,  sQD        ;E\nE::EpLgBLPQr7QOppg6: sH\nO: .r, ,QBL 2RO6KwGKHQU\nO:   r.caSS  c56L;UpRBJ\ng:   rXgp6EPJp6w2QBQgX2\nE:   :1RRDKaZOGBQBMGsa2\ngL    .rSw2pDZPDv J1r2S\nGE       6OKHMSSZDHJ:w5\n6G:r  .XRBB:   :DEGOBBn\nwBXKXBQBB.   .1H11a1rDU\n1Q, rBBBB7  pKXPJPSU;;p\nJBQ  :ZBQBBBQUUUwDDZ:iK\nSgpQ    :EBBBBBZ: :Rw1K\nX ;BB6sL   ,7BQBBr , 7K\nHr;65K6pGSr  wBBBBBZ rP\nrsL7scLvLLs2Jc7r7r77sJ7\n",
   " 7ZpP2spHp;.7PvHU;,:KZp \n 7QRJGGsZBBB ;Zp5pJrE::Q\n 7Z2PSpHELSDJZwwaa5gHr;R\n s5wpP6ZUX2SXR6EHHLBB :B\n L6,;:.rHX5K7r;,DJ;:H :Q\n LQ,:KJ rgK6 :S: RBL:::B\n vB: 7;.aKKZ..;.;2 :Qr,Q\n vQgQr:RO6HE2572EPw;: .B\n cX:Z  :SaGPQgpGPKPBB .M\n 7BGZS;      ,JLJJc cr,g\n rRZQKBRBg2:77v.UPr HBBH\n rQBBBQ5BBREBRBKBpBHREQH\n ;BBBBBBBBQOBQQXBQBaQQB2\n rBBBBBBBBBBQBBBBBBBBBQU\n iBBBR6LUgBQBBBBBQBBBQB1\n 7Xwac, :1aBBBBBBBBBBBQU\n 7PsJ7  L7sRMQBBBBBQBBBS\n rBB6;rr,,1J7LcsLJssLsSP\n :7L7sLJsssL77rrrrrrrr7L\n",
   "P rrr;;7r7r;::;;:;::;:r\n X,B UP      :1gRBQ,7HpB;\n a:5 rBr   .rUwHw;  BJ2Z;\n H,P ,BQH.,2RgU,   wZ. Z:\n a,P  sBDg6 6gR  rEPHDPQ:\n H,6   ;pEO:ra5RRQRRZBgg:\n X,P    .HLiS:rsBgOPr.7R;\n H,p  :2cLrr1:.r:  7E  E;\n a,P  7:.,a7JPPH:cBJ ,.B;\n K,6      :rMBRgX1; ,7.R;\n a,K  ,S  1,7r.    U EBP;\n H,6   B:cBr  7s  QM   Z;\n X,K    r2,  .BB.;:LJ  Er\n H,p  BB:HB  .B5 :.BO  gr\n X,H   J  L  :K,.: K7  gr\n X,p ::;     E5 ,,:R:  gr\n a,K  ::;:   wE.:.cB;  Dr\n S,G  : :       BB     Qr\n p Hs7rJvrcsccrr7L;77vsZ,\n",
   "SQBBQBBBRgRREgGRODDRGQL\nG    7,  1KGMgOPa :RLG1\nD;  : B. s;.:7..aBB: 7P\n67s wE;B JB    MBa   1P\nD  OpBgM :B. :BB;    wZ\nE  7BPULr:12;rHr     2p\nE 2gP;rOU:7GRO       wZ\nH aMD,;Q15SpKOQ,     Up\nKML:  .DHP7.rssr     1Z\n2OL ,Bv.PcrBB. 5s    Up\nHwBK XBJs BQB UBB5   wZ\nH.pBr BBB HBB ZBQB   2p\nG. BB LBQ wBB BBBB   Lp\nPJ 7BBDBHsUpB;pQ,B   JS\npr..,rgBBL.;K. ;;SQpGQJ\n5RcOZU,,JH:,.r7,.5DDBB7\n5BB;,r5i,.:,:ZZPBGKBBB7\n2QBJ;,ic;:XBBw..ZQBBBR7\n7LLJs2SwJ5wsv1J1c7rrrL7\n",
   ": rr;:..,:,,,::.,. .,,;i\n:5:   QBBRRBR HBQBBBBBB:\n:2;   BBBBBBB7BQBBBBBBD:\n:5; .ZBBQBQBRacLJBpLLcP;\n:2;   SBBQBsLXw12JS22JB:\n:5;     ;RX7aa2XHPa51EM;\n:2i      LLJpUZH.;SSZHg:\n:S;  wBBBErcXSaS:JESX2S;\n:2;  OBQBBBKHapZOXE2w1M:\n:5: 5BBBQBBBgHPw2gwwaRB:\n:U;     7BB5  gBB7LBBQB:\n:5;  ,: :    JQBB  BBBB:\n:2;  .ZJgp  aZ; OL  B;p;\n:U:  OQrRBBBX.      : Ur\n:1:  QBDRaGg7Zs.   :v7M;\n:7gU:rrMBg;:.:,:;1MBggD;\n:rQpg6v      ,5rRERSQQB:\n:rG25PXK;UX,  ,U2QBMHUQ;\n:;aUJUswU21SUPKS1w1SS6E:\n",
   " .,.......::77c777r:rr7:\n1BBQEErr:       :;gv. sw\nHp  :J  K       ii1:r rJ\n6L :r;B:rr,     7r;,B :1\nEw    BB  BB.Q; LrJ.XXL7\nE1 UB7 :v. L.aB Bir BBr7\nG1 :sDBB;;c;r ; OB r 1B;\nZU    .  aBOPg:: r.,7BBr\nEJ          r rBK::,H :s\nPH          ,BL  RB   Ks\nSBPLrRUJXBBKJ2;  cBBB Js\nHJJBrwP;1Z.5JSBR;:  ; v2\nE7 ;s  ig rM:1;;DO;:  sJ\nZw  rL cr.D:rE Z1BsZw r1\nG1 ;21srr7v:7r:r.D 5B Kc\nZw rKSRi;r,. ;1  ,vB, 2s\nEs Q:.X     7BBgcLBB BBr\nZ1  ,.; O1 2i..pB: Ls1vL\nsQ::r.;iBB.RB;,:7DR::LB:\n",
   " .,...................., \n2QUS2aSXpOORDD6H5SU5UpQ,\n2Dww5UEgps7;rLHOD5U1w5R.\nJDJ2Sg1.        7gHUJ5D.\nwOw2R:            GXwUg.\nJg1Di             .g2aD.\n1OUZ               2PUg.\nJg2O               SXSg.\nwO2Gr             .DU5R.\nJDJSD:            6K15g.\n1GJsU6L         7GPww2g.\nJ67LsUZQGSvrrsUEXscsL5D.\nsQMBBQBBBBBBBBBBBgZ2LLG \n7BQBBBBBBBBBQBBBQBBBBRG \nvQBBBBBBBBBQBBBBBBBBBBQ \n7BBBBRDMQBBBQBQBQBBBBBR \n7BBaL: rsDBQBBBBBBBBBBR \n7BRv7  PsLBBBBBBBBBBBBR\nrOBBBBBBBRRDRggDRgRgRRp \n",
   "ir777rr::.:.,...,..., :\nrg    ;;7rMr:ZPpRBOGpZR:\nrP   JapXs1:2J6U .Z55pM,\n:BQP 7rs5BgSgKXr  gRGGM:\n:BBBBH;   BBsrL2B7.rr Z:\n:BBBBBB  ;gQ2.  .:    Z;\n:BD::OZsBBBBBBB.      g;\n:QX1HSSrOBBBBBB       D;\n:McpZaScw1BBBQB       g;\n:BaXHO.5H6OZEBU       D;\n:B71KP26gDBgasG6;     R;\n;ZwE:;pZUcaBBBBBBB:   O;\n:RZrL,LBB2LJQBgEBQRr  g;\n:BBJXBBBBBZ2ppXRUQwB. G;\n:QBBBQBB  ;wXJ2U2XXE; P:\n:BBBBBB6,::vZpKpaPwr,:g:\n:RPKGZEDBBBOXXEpSw5XZOB,\n:MGpSGBBBBQBQZ5PPGPp2XM,\n,Ua55wU25252U2SXKLLLLJa.\n",
   "rXL7Lsvc7LJJ11sS7rr7JJJi\nS7pO5EGHwHrr  r gBBR:rUw\nK; sPZXpZQBB1:BR122SsraJ\nUB;;Mg1rBBBBBBBSp6s5gw5J\nSXJ7,   BBBBBQBLaUaJsiss\nUs1P    BEBBBG6P22SO7c2s\nUwXirPrr   BQs1pKSJv.MKc\n1BD.:;:H,  PLSXHEBBQBBR7\naQ ,;        .KH rBBBBQr\nHR .Pc:,rJZUa52s ,BBBB57\nPg  sOB6aJ2sPaJ5RprsBO7L\nKK .,:,i:r.:::..:r,,Urr1\nKp....,.,,,7... U6;:J:1J\nHr7s:.5r::sHr..;:  Z;:vJ\np7::7.1    ,Ur.s  vLs:Us\npr::;;:     r1cr ;K;:ZBL\nO,,7Lr      17w  Hc1wBB7\nE,.v;J     SBO. 17SEHDB7\nJH::;:;r7rr;w2XL2J221J2; \n",
   "QU,......,:::::::::iB ,\nB                   g.:\nB ,BD6ZOB   .;      R.:\nQ  RSBpaH ,EBBZ     R.:\nB  OpQQs51BBBBBL    Q.:\nB  E2gPsLBBBBBBP.   R.:\nQ: s5GQ57QBBBBBMv   M.:\nZw;rs5RM7PBBBBBBJ   R.:\npBBM27HRJ7BBBBBQL   Q :\nSBQBgLPSQL6BBBBBs   R.:\nXBBBBUX1BH7QBQBB7   Q.:\n5BBBBBUa6McUBBBB7   R.:\nXBBBBBQrcG5rpQBBr   M.:\n5BBBQBBQ77as;KBD:   R.:\nXBBBBBBBBJUXULMgBc7 O :\n5BBBBBQBQBQBBBBBQBH Z.:\nHBBBBBBBBBBBBBBBBB1 p :\nXBBBBBQBBBBBBBBBBBs D :\nLLc77r7r777r7777vsLsP r\n",
   " vJs2pP1LJJHpZpS2E6GZZa.\n SBBS  5OSXL.  Q;     Z:\n Xgc,sgSHLJZGpOO      G:\n Oi  g2Hp::GUHBr.     G:\n Or RBQXUPP67QBEBB    D:\n gi BBpvXG11garHDL    E:\n Gr 5BpvEBEsE   :7w;  G:\n GiXQDGsSQXL25a2X6pB. a:\n Er 1sJ1HQB2wpwHXwHa61M.\n g7    P1QD67KaPr:1gGMB.\n Oc  LBEsJDQsLPcZaJP; a,\n gr 7BPZ5spgRcSBBBK   a:\n E: Q2J5pSMcggr6BBBBBrU,\n p2cZa6rsOXDRRJ7RBBBBB2,\n 2BBLgQ5pHPKaRBL7BRJ5.5,\n PcO  rv Sg5cL5Zs5:   P:\n 6;P. .Qc   RLc1G567  Z:\n O; B  :   BQBODggZBE X:\n UE;.sg6MBRRH  ,..;1;;g.\n",
   " rUr;vr;rr7777vrs;rLJsX.\n XH . EZ::v L,r;rBp:  G:\n ps 7Gr,s2RRggRp.77:  G:\n Hs Bp;:sGS2U1EHr .r. O:\n P7.: HXraLDHL5XXGQa  Z:\n SaEBi;;:SURBJXpa6P7L:g:\n aD. , DBwsQRJwP2SRZs,O:\n KL:E  ;G1XQpvSXUUK:  E:\n pc a  c;J6BPLX1DBM7  G:\n Sg.:,;QRsPQULOBsgB.  g:\n 5G:2p..KOXRLa:7      O:\n wZLG6UsZgOQ1BJ .   . G:\n JBHSU6HLpQ5ssL:Lr 2B:H:\n 1MaPaELspDLaLHK:wg:  O:\n Hr:sZwwpZ7PKKUO2.gB, O:\n a5 7ZUXP1X6UXJZBZ    g:\n UQr:SKSr71Q5UgB ,    O:\n aJ.B:.,,LB;1.:B.     O:\n i5r,:LUc:;riir:7csLcsa \n",
   "JpUwSUS2SUSU517rsw52U5Z:\nG             2B.     ar\nPr.iLKOBs   .r :. MB. H7\nHDBMGKXSRK  wQG r sQ: Xr\nP. wS21UwO6  BD.i ,gs U7\nE. :RH11U2GS iP.;, JK 1r\nZ  BB:52J2wEc;H; : rK s7\nP; r, BX1J22PiSZ:: pB sr\nUBQ.:JG11212JDQX.: BB J7\nUOU : .gBs2JwsBU : 77 2r\n2pX..,.77UJwJ1aw.;.a7 27\n2Jg1 7 7BQJJwJSR., J1 Ur\nUrap.:, ,r5w12UX :,BQ s7\na:US. 7 HBEsw1267.  : wr\n17B:   ::KpUw1J6g  BQ:77\n5,HsBB  rXRPSPg2E  L. sr\n5BS:7 :,,2; :B2 B7 ,sMR;\nSJ: : BR.BX r:c.vr. RvK;\n.;L;7ss77rv:;JJcscv1wcss\n",
   "U:::::::r7LcL77ir2r1U\nB:......:        MU :B\nB  1BGOZOBw      PB  B\nB :O5wU26S     ZBP  .B\nB  G12JU5g    pBB   .B\nQgiH2121Ugi  sBB:   .B\nO.HMS11wwKp  BBs    .B\ngJp 2U2JU2Z:MBB,    .B\nDgG::612J2sOBBLB.   .B\nDLXB:;S12JwsDsZ2  .a B\nGB rwLpJJwJ1LZ2, LQ, B\nMU wZZEwLJ1J11rBBBc.:Q\nRRrPH7vBavsscLJBB.J; B\n6BR r GBBErsHKGr7DZ  B\n6gBB;;OBQB7BBB: gB  .B\nZBBBB, BBQBBB1 pB. ssQ\nE:7BBg ,QBBBZ 6BBBB. B\nRQ ,BB  QQBBXwBQBE   Q\n1r5K:2pcrJJLsLJ2r:v7Xa\n",
   ";ivcLcc7r,,.,,:,:;rrr;\nB,    .;;sU1KXEg;    B.\nB. :BBEBD.    ,sZp:  B.\nB7;;BBMEQBU7pBBGJS:  B.\nB,:QBBBspKBPBc       B.\nB.   :XPQBBZL ,11r   B.\nRB7    X66BX2BBQBQBD g.\nZwBBBBBO7PDMsQBBBBBB,D \nDsBBBBBBJ1QPLJBBBQBBQR \nD,GBpOEaXwOw6KHGBBBR7g \nD;1J1a25O2gBgBO      Q.\nESX2121S;5aRZpBg     B.\nDZpUP2HL.vpcJOgRB    B.\nGHEaJGXUGpXPsZRBDg   B.\nOLKUJUw1wwPSKL25sHM. B.\nR.DBUJsw26JLLH5HXE6D:Q.\nB BQBQBBREBQBBBBBQR  B.\nB  BBBQ2  RBBBBBQBB  B.\nQ; L       .Zv :;:,,:Q \n",
   "r;;::7sLsssLsLcvr;cvL ;\nB.irra:.LpUS26;,Lr5  sw\nB :PO:J:EMgOgQOrr:r  J2\nB  ,LR::QKaXaOUL:c,  Jw\nB   :;raDaX5aGJ7;H;  JU\nQ      :QXSaSR:r;Dc  J1\nB      2RaaSaQB7 5Bi L2\nBG.g   BHXSaR; L.5r  sJ\nB6O.:;sgKSXXBQ: L LB771\nBKp,;XRHSXXB;  .a,.. 7J\nBr7:vKZSXSZK  ; ,  BDr1\nB   SRaXSPB.  RB:i:r cJ\nB  PBOOEgZBB Br  s7  sU\nQ sBGOEZOr i:.c  BB, L1\nB        .,:7.;7  ,7 J1\nB       MB:  rBB ..7 Xs\nB           sJ.:.QB .5J\nB           .BP  p,  2J\nBU;irrrrrrr;::ZBH2r,:Dr\n",
   ",:::;:;:;::::::,. ..:.;;\nK7         ,7cvs;:7Z, :K\nH:       7RHSGSLL;:Zc .S\n25  .:, ,Xg .7r    :B: a\n2s1QBQG;LRB;;    JDJ,sv1\nJHrwLr:r;:1Bri75MBQi  ,a\nSg,     ,JZMBBBBBBD   ,S\nS;       PBRwci ,QBBL .a\nH;       7.       ,rwLr1\nw;                    :a\ncBBQBBBQBBBGUr.        U\nrBBBBBBBQBBBBBQBBBBRw:;L\nrQBBBBBBBBBQBBBBBBBBBQBi\nrBBBBBBBBBBBBBBBBBBBBBB;\nrQBQBBBBBBBBBBBBBBBBBBB:\nrBQBBBBBBBBBBBBBBBBBBBB;\nrBBBBBBBBBBBBQBBBQBQBBB:\nrBBBBBBBBBBBBBBBBBBBBBB:\n;PEHKXHHKHKHKHPHPXKHppK,\n",
   ":SHKHSsJr7r7L7rvUPHpHHJ,\nvD,   ,.E2SHisKL .,,,,E;\n1w   ;2:PUEpLOHJ,     cs\n2s,D5UREQBB1;cL5H     sL\nww LMUii ;5  .::      cL\n21       :RpDEXKBBBB; 77\nsL       ;DEBBXBBBBBBBR;\nrBBBB    rgPBMBOBBBBBJLr\nrDBBBBBBJUSKgg2SX.    rL\nrQBBBBBBBUOBBHsv.rs   Lc\niBBBBBBBgSSa1s1BBBQB, 7L\nJc,5SQBBEgSDULRQBQBBB:;c\n11    6MpgDBs5BBBBBBB ;L\n5U    :Xw1gQa2K7rPEB. ;v\nwa   ;RaRgRa6pv1SrsBgwJr\nUU  :QK1RQBp,XJri:wrBBB:\n2U ;QGwXSsrrLZDg2sS5BBB:\nUJ;BgHgP5Bv:Z:r1:rBBB2J;\n7M:,:,  ,QOJDRMrrL...,Zi\n",
   ":,,,:.,,::,.;r777r;.,, \n.BpRSs5gKXKBg  ,    BBB7\n.p7PZpKX6PZO;  :BBBBBBB;\n BRaXZXHUHpg     JBBBBB;\n.D7PHKssJ5XP     JBBBBB;\n.J ZPHJgOQMG  .MBBBBBBQ;\n QBG:12gBQBO  rv:.  2BBi\n BQBQBJXXBRZ:      .PBQ;\n BBQBB17OQMaR7  ;gBv.B.r\n BBBBBKLSQXJ6DPXQQO. . 1\n BBBBBBsaa5H5ZX6E5Pi   J\n BQ: 6Bg5BpBHa222KKBBBH1\n.B     1GREaBKXLX5Hci :1\n.Z      Q52GQUHZHOR,   U\n.B,     7DEgMQE67vBQ   s\n BQM7.   wS2BP1K7  BBRO7\n.arQBRw  ;MXQEOOQw ,BBBi\n.K sOEGEPgQc.,:::gBBQBB;\n 6rJw2SwK1wS;,..,..Bp7Z:\n",
	};
	
	vector<string> c[20];
	for (int i = 0; i < 20; i++) {
		vector<string> a = (vector<string>) Split(cards[i], '\n');
		c[i] = a;
	}

	vector<string> t1 = c[i-1];
	vector<string> t2 = c[j-1];
	for (int k = 0; k < 19; k++) {
		cout << t1[k] << "           ";
		cout << t2[k] << endl;
	}
}

vector<string> Split(string str, char delimiter){
	vector<string> internal;
	stringstream ss(str);
	string temp;


	while (getline(ss, temp, delimiter))
	{
		internal.push_back(temp);
	}

	return internal;
}

// 게임 시작 화면 출력 함수
void start() { 
	cout << "LUS2QDBRssRgw2JKRMp1S1BEHHpppHPH6ppHpp6XHXpppHpppHPX6pPHpp6HHH6ppHPppXKXpPPXKZO2\n7SSSU52Uw15ggRZKJ22aZBB;,:::::::::::::::::::::::::::::::::::::::::::.,sRKBR66KXU\n7wSwU52QUE22SUSUSZB                                               ;2;  : ;BrEKHU\nLH5aXGQsLRUaSXa6QB:                                              ,U7  Bs   rEZPa\nLKPZgJ                                                       7aSp          sgZKa\nJKZKgs                                                       :7;r          cgP6a\ncKP6R1                         L;:                                         sg6H5\ns666DJ           ,BBQRHv        igPZQZ                  :SRggBg            Lg6pK\nsXppRJ             2gKDQK        U6agw    22r::;LSRBgw:   cOKpB            sR6PU\nLHKEg1             rGaaR:  7Xv;;;PXagc   sBBRMMBBBQBBBB   :RaZZ            sgEH5\nJPEPgL             H6SPG:  UBBBBB6HSRc    ;gPXDr. . .:.   rRXPE            cRpZS\nLap6MJ           rBRBP  ggDQ1    SZSgv     HZXM.          rgHap6BQBc       sM6PU\nspppDs         :RBBP:    QQBB    PZHgL     XZKR,          ;RaXH6QBBc       LDZpH\ncHHER1                   c1i,    gBBBi     GPXg:        : :Rap6            sREH5\nJK6pgs                   iQgQMM:  i:      2BPHG1rrcJXOBBO ;gHPO            LgppS\nLpp6DJ                   ,66HGO           ,BBQRBBBBBBgL.  ;Ra6E            sg6PS\nsSp6QJ                 :6QDgRMRGgE65J,      ;;;:;:,       iRHpg            sM6PU\nspPZDJ              :UBBBBG7 ,rXMBQQBB;                   rB6MQ            LDEPX\nsKZPRs           XQBBBZs;        :pQBg.                   iBQg;            cRp65\ncHHEgL           ,.                                                        sRZH5\ncSEQRU7L                                                           rQ:B   .BBOE1\nLSgDgs.                                                          sO,7s  r  LgP6X\nJgpKpJ    .                                                          : KJ, 7GpHP\ncXK66s7U. 7  ;                                                      r   ,  rO6HU\nsPZKp2:J .. BQ                                                     .BBPRgS7pKKOp\nLKPpPOc ;;  , 7;                                                  KBpKHHXKMBgOEK\nsSpPppOgBQ2s7:Bgr7c777v777v777v7c777v7c7777777vv7777c7v7v7v7v777rMB5a5S5SJQQ5cwc\nsUHXXaXaXUPXpZ5aKHPXKXpHPHpHPXHHPHPHPHPaHXpHPHPHpHHXpKKHPKPaHXgEg5s12J21wJsLSUwL\n" << endl;
}