#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// Renkli uyarý yazýlarý için kullanýlan fonksiyon
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// hastanýn muayene ücretini ödedikten sonra kalan bakiyesini hesaplayan fonksiyon
void kalan(int bakiye,int ucret){
	if(bakiye-ucret<0){
		setColor(4);
		printf("yetersiz bakiye!!");
		setColor(7);
	}
		
	else{
		bakiye-=ucret;
		printf("\nKalan bakiyeniz %d \n",bakiye);
		printf("\n--------------------------------------------------------------------\n");
	}
}

int main() {
	
	//hastane randevu sistemi yönetici girisi için sifre 1234'dür
	// þifre ve ücretin ayrý yerde olma sebebi sabit olmalarý ve deðiþtirildiði zaman döngüde tekrar ayný deðerlerin atanmamasý için
	int sifre=1234, yenisifre=1234,yeniucret=0, kasa=0, ucret=1000,n=2;
	
	//sonsuz döngü kullanýldý iþlem sürekli baþa döner çýkmak için 3'e bas	
	while(1){
		
	int  bakiye=0;
	int giris,i=1 ,islem, secenek, yas, devam,devam1, gun, ay, yil, saat;
    char kullanici[100];
	char poliklinik[5];
	char odeme='e';	
	
		// Menu giriþ ekraný burada giriþ tipi seçilir
		printf("-----------------------------------HASTA RANDEVU SISTEMINE HOSGELDINIZ-----------------------------------");
		printf("\ngiris tipi seciniz:\nYonetici girisi 1 \nHasta girisi 2\nCikis icin 3\nSEC==>");
		scanf("%d",&giris);
		printf("\n--------------------------------------------------------------------\n");
		
		// giriþ 1 yönetici ekranýný açar	
		if(giris==1){
			
		//dosyalama iþlemi yapýldý yönetici için kullanýcý adý ve þifre txt dosyasýnda saklanýyor
		FILE *dosya;
		dosya=fopen("yonetici_verileri.txt","a");
		if(dosya == NULL){
			printf("Dosya acilamadi");
			return 1;
		}
		do{
			printf("\nKullanici adi giriniz:");
			scanf("%s",&kullanici);
			printf("\nSifre giriniz:");
			scanf("%d",&sifre);
			
			fprintf(dosya, "\nkullanici adi %s sifre %d\n",kullanici,sifre);
			printf("isleme devam etmek icin e bilgileri guncellemek icin h\n==>");
			scanf("%s",&devam1);
		}while(!(devam1=='e' || devam1=='E'));
		fclose(dosya);
		printf("\n--------------------------------------------------------------------\n");
		printf("\nverileriniz dosyaya basariyla kaydedildi\n");
		printf("\n--------------------------------------------------------------------\n");
		
		
		
		//þifre	kontrolü ve yöentici iþlemleri menüsü
		if(sifre==yenisifre){
			setColor(2);
			printf("\nYONETICI OLARAK GIRIS YAPTINIZ\n");
			setColor(7);
			printf("\n--------------------------------------------------------------------\n");
			printf("\nHosgeldiniz sayin: %s\n",kullanici);
			printf("\nIslem seciniz\n\nSifre degistir 1\nMuayene ucreti belirle 2\nHasta sayisi belirle 3\nSEC==>");
			scanf("%d",&islem);
			
		//iþlem 1 þifre belirler	
			if(islem==1){
				printf("\nYeni sifre belirle: ");
				scanf("%d",&yenisifre);
				sifre=yenisifre;
					if(sifre==1234){
						setColor(4);
						printf("\nYENI SIFRE ESKI SIFRE ILE AYNI OLAMAZ!!\n");
						setColor(7);
					}	
					else{ 
						setColor(2);
						printf("\nSifreniz degistirilmistir\n");
						setColor(7);
				}
			}
			
		//iþlem 2 muyaene ücreti belirler 	 
			if(islem==2){
				printf("\nMuayene ucretini guncelle: ");
				scanf("%d",&yeniucret);
				ucret=yeniucret;
				setColor(2);
				printf("\nMuayene ucreti degistirilmistir!\n\n");
				setColor(7);
			}
			
		// müþteri sayisi belirleme	
			if(islem==3){
				printf("Bugun gelecek hasta sayisini belirle: ");
				scanf("%d",&n);
				setColor(2);
				printf("\nHasta sayisi belirlendi\n");
				setColor(7);
			}			
		}
		
	//hatalý siþre giriþinde sistemden çýkmak için kullanýlýr	
		else{
			setColor(4);
			printf("\nHatali sifre girdiniz\n");
			setColor(7);
		}
	}
	
	
	// giriþ 2 ekraný hastalarýn randevu alma ve ücret ödeme ekranýný açar 		
	if(giris==2){
		
	//hastalarýn ad ve soyad bilgilerini alýp for döngüsü ve dizi kullanarak verileri listeleme 
	char ad[n][100];
	char soyad[n][100];
	for(i=1;i<=n;i++){
		printf("\nAdinizi giriniz:");
		scanf("%s",&ad[i-1]);
		printf("\nSoyadinizi giriniz:");
		scanf("%s",&soyad[i-1]);
		printf("\nYasinizi giriniz: ");
		scanf("%d", &yas);
		printf("\n--------------------------------------------------------------------\n");
	
	//özel durum sadece gazi ve þehit yakýnlarýndan ücret alýnmýyor	
	printf("\n\nOzel durum seciniz:\n1)Gazi-sehit yakini\n2)65 yas ustu\n3)Ozel durumum yok\n\nSEC:");
	scanf("%d", &secenek);
	printf("\n--------------------------------------------------------------------\n");
	
	// seçenek kontrolü ile hastalarýn özel durumlarýný belirleyip döngüye alýr
	if(secenek==1 || secenek==2 || secenek==3){

	// devam deðiþkeni döngüyü baþlatýr		
		printf("\nMuayene islemi icin 1\nIslemden cikmak icin 2\nSEC==> ");
		scanf("%d",&devam);
		printf("\n--------------------------------------------------------------------\n");
	while(devam==1){
		if(secenek<1 || secenek>3){
			setColor(4);
			printf("\nYABLIS KAREKTER GIRDINIZ");
			setColor(7);
			return 0;	
		}
		
	// randevu ekranýný 
		if(secenek==3){
			printf("Poliklinik seciniz:");
			scanf("%s",&poliklinik);
			printf("\n--------------------------------------------------------------------\n");
		// bakiye bilgisi alma ve ödeme ekraný
			printf("lutfen bakiyenizi giriniz:");
			scanf("%d",&bakiye);
			printf("muayene ucretiniz %d TL'dir\n onayliyor musunuz? (E/H): ",ucret); scanf("%s", &odeme);
			
			     	if(odeme=='e' || odeme=='E'){
					   	if(bakiye-ucret>=0){
					   		setColor(2);
					   		printf("\n\nISLEM ONAYLANMISTIR\n\n");
					   		setColor(7);
					   		kasa=kasa+ucret;// gün sonu için ödenilen ücretin toplandýðý yer
					   		kalan(bakiye,ucret);
						}
						// tek seferlik tekrar bakiye sorma ekraný
				   		else{
				   			setColor(4);
				   			printf("\nYETERSIZ BAKIYE\n");
				   			setColor(7);
				   			printf("lutfen bakiyenizi tekrar giriniz:");
							scanf("%d",&bakiye);
							printf("muayene ucretiniz %d TL'dir\n onayliyor musunuz? (E/H): ",ucret); scanf("%s", &odeme);
							kasa=kasa+ucret;
					   		kalan(bakiye,ucret);
						    }
							  
					    }
					    
		   		    else if(odeme=='h'|| odeme=='H'){
				   	   	setColor(4);
						printf("\nISLEMINIZ REDDELIMISTIR\n\n");
						setColor(7);
						break;
						}
						
						
				   	else{
						setColor(4);
						printf("\n\nGECERSIZ KARAKTER GIRDINIZ!!\n");
						setColor(7);
						break;
						}
						
						break;		
				}
			
	// gazi ve þehit yakýnlarý için ücret alýnmaz direkt randevu oluþturulur		
		if(secenek==1){
		printf("Poliklinik seciniz:");
		scanf("%s",&poliklinik);
		break;
		}
		if(secenek==2){
			if(yas<65){
				setColor(4);
				printf("\n\nYANLIS BILGI GIRDINIZ\n\n");
				setColor(7);
				break;
			}
			printf("Poliklinik seciniz:");
		scanf("%s",&poliklinik);
		break;	
		}	
	}
	if(devam==2){
		setColor(2);
		printf("\nISLEM IPTAL EDILMISTIR\n");
		setColor(7);
		break;
	}	
}
	//yanlýþ seçenek seçildiði zaman uyarý verir
		else{
			setColor(4);
			printf("\n\nGECERSIZ GIRIS YAPTINIZ\n\n");
			setColor(7);
			break;
		}
		
		
	// randevu tarihi belirleme ekraný uygun zaman aralýðý seçildiði zaman randevuyu yazdýrýr
		if(devam==1 && (odeme=='e' || odeme=='E')){
		do{
			if(secenek==2 && yas<65) break;
			printf("\nRANDEVU TARIHI BELIRLE\n");
			printf("Gun giriniz: "); scanf("%d",&gun);
			printf("Ay giriniz: "); scanf("%d",&ay);
			printf("Yil giriniz: "); scanf("%d",&yil);
			printf("saat giriniz: "); scanf("%d",&saat);
			
			if(gun < 1 || gun > 31 || ay < 1 || ay > 12 || (yil != 2024 && yil != 2025) || saat < 7 || saat > 17){
			setColor(4);
			printf("GECERSIZ TARIH GIRDINIZ\n");	
			setColor(7);
			}
			else{
	  		    	printf("\n--------------------------------------------------------------------\n\n");
			  		printf("Ad: %s\nSoyad: %s\n",ad[i-1],soyad[i-1]);
					printf("%s poliklinigi  \n",poliklinik);
	   	  			printf("%d %d %d tarihine\n",gun,ay,yil);
		  			printf("saat: %d.00 'a ",saat);
	   		  		setColor(2);
		 			printf("\n\nRandevunuz olusturulmustur\n");
		   			setColor(7);
		   			printf("\n--------------------------------------------------------------------\n\n");		  			
			}
		}
			while(gun < 1 || gun > 31 || ay < 1 || ay > 12 || (yil != 2024 && yil != 2025) || saat < 7 || saat > 17);
	}
										
	// Gün sonu alýnýr gelen hastalarýn listesi gün sonu muayene ücretinden gelen gelirlerin toplamý ekrana yazdýrýlýr				
	if(i==n){
		setColor(4);
		printf("RANDEVU LISTESI DOLMUSTUR");
		setColor(7);
		printf("\nGun sonu alma(yonetici icin) 1 \nCikis icin 2\nSEC==>");
		scanf("%d",&giris);
		if(giris==1){
		printf("\nKullanici adi giriniz:");scanf("%s",&kullanici);
		printf("\nSifre giriniz:");scanf("%d",&sifre);
		if(sifre==yenisifre){
			setColor(2);
			printf("\n\nYONETICI OLARAK GIRIS YAPTINIZ\n\n");
			setColor(7);
			printf("\n--------------------------------------------------------------------\n");
			printf("\nHosgeldiniz sayin: %s\n\n",kullanici);
			printf("Islem seciniz\nGun sonu al 1\nSEC==>");
			scanf("%d",&islem);
			if(islem==1){
				printf("\n--------------------------------------------------------------------\n");	
				printf("\nbugun gelen hastalarin listesi:\n");	
					for(i=1;i<=n;i++){
							printf("\n%d. hasta %s %s\n",i,ad[i-1],soyad[i-1]);	 
						}
						printf("\n\nKazanc: %d\n\n",kasa);		
					}		
				}
			}
			
		// Güm sonu ekranýnda çýkýþ yapmak için kullanýlýr	
		else{
			setColor(2);
			printf("BASIRYLA CIKIS YAPTINIZ \n");
			setColor(7);
			break;
		}	
	}
	if(!(devam==1)){
		setColor(4);
		printf("\nHATALI GIRIS YAPTINIZ!!\n ");
		setColor(7);
		break;
		}
		// ödeme=h olduðu zaman sistemi yeniden baþlatýr amaç hayýr a basýldýðý zaman ismin listeye kaydedilmemesi
	    if(odeme=='h'|| odeme=='H'){
	 	break;
	 	}
		 if(secenek==2 && yas<65) break;			
	}
}

	// döngüden çýkmak için kullanýlýr ve sistem kapanýr		
	if(giris==3){
		setColor(2);
		printf("\nBASARIYLA CIKIS YAPTINIZ\n");
		setColor(7);
		break;
		}
	// yanlýþ giriþtem dolayý uyarý ekraný	
		if(!(giris==1 || giris==2 || giris==3)){
			setColor(4);
		    printf("\n\nHATALI GIRIS YAPTINIZ!!\n\n");
		    setColor(7);
		}				
	}
	return 0;
}
