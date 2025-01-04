#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// Renkli uyar� yaz�lar� i�in kullan�lan fonksiyon
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// hastan�n muayene �cretini �dedikten sonra kalan bakiyesini hesaplayan fonksiyon
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
	
	//hastane randevu sistemi y�netici girisi i�in sifre 1234'd�r
	// �ifre ve �cretin ayr� yerde olma sebebi sabit olmalar� ve de�i�tirildi�i zaman d�ng�de tekrar ayn� de�erlerin atanmamas� i�in
	int sifre=1234, yenisifre=1234,yeniucret=0, kasa=0, ucret=1000,n=2;
	
	//sonsuz d�ng� kullan�ld� i�lem s�rekli ba�a d�ner ��kmak i�in 3'e bas	
	while(1){
		
	int  bakiye=0;
	int giris,i=1 ,islem, secenek, yas, devam,devam1, gun, ay, yil, saat;
    char kullanici[100];
	char poliklinik[5];
	char odeme='e';	
	
		// Menu giri� ekran� burada giri� tipi se�ilir
		printf("-----------------------------------HASTA RANDEVU SISTEMINE HOSGELDINIZ-----------------------------------");
		printf("\ngiris tipi seciniz:\nYonetici girisi 1 \nHasta girisi 2\nCikis icin 3\nSEC==>");
		scanf("%d",&giris);
		printf("\n--------------------------------------------------------------------\n");
		
		// giri� 1 y�netici ekran�n� a�ar	
		if(giris==1){
			
		//dosyalama i�lemi yap�ld� y�netici i�in kullan�c� ad� ve �ifre txt dosyas�nda saklan�yor
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
		
		
		
		//�ifre	kontrol� ve y�entici i�lemleri men�s�
		if(sifre==yenisifre){
			setColor(2);
			printf("\nYONETICI OLARAK GIRIS YAPTINIZ\n");
			setColor(7);
			printf("\n--------------------------------------------------------------------\n");
			printf("\nHosgeldiniz sayin: %s\n",kullanici);
			printf("\nIslem seciniz\n\nSifre degistir 1\nMuayene ucreti belirle 2\nHasta sayisi belirle 3\nSEC==>");
			scanf("%d",&islem);
			
		//i�lem 1 �ifre belirler	
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
			
		//i�lem 2 muyaene �creti belirler 	 
			if(islem==2){
				printf("\nMuayene ucretini guncelle: ");
				scanf("%d",&yeniucret);
				ucret=yeniucret;
				setColor(2);
				printf("\nMuayene ucreti degistirilmistir!\n\n");
				setColor(7);
			}
			
		// m��teri sayisi belirleme	
			if(islem==3){
				printf("Bugun gelecek hasta sayisini belirle: ");
				scanf("%d",&n);
				setColor(2);
				printf("\nHasta sayisi belirlendi\n");
				setColor(7);
			}			
		}
		
	//hatal� si�re giri�inde sistemden ��kmak i�in kullan�l�r	
		else{
			setColor(4);
			printf("\nHatali sifre girdiniz\n");
			setColor(7);
		}
	}
	
	
	// giri� 2 ekran� hastalar�n randevu alma ve �cret �deme ekran�n� a�ar 		
	if(giris==2){
		
	//hastalar�n ad ve soyad bilgilerini al�p for d�ng�s� ve dizi kullanarak verileri listeleme 
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
	
	//�zel durum sadece gazi ve �ehit yak�nlar�ndan �cret al�nm�yor	
	printf("\n\nOzel durum seciniz:\n1)Gazi-sehit yakini\n2)65 yas ustu\n3)Ozel durumum yok\n\nSEC:");
	scanf("%d", &secenek);
	printf("\n--------------------------------------------------------------------\n");
	
	// se�enek kontrol� ile hastalar�n �zel durumlar�n� belirleyip d�ng�ye al�r
	if(secenek==1 || secenek==2 || secenek==3){

	// devam de�i�keni d�ng�y� ba�lat�r		
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
		
	// randevu ekran�n� 
		if(secenek==3){
			printf("Poliklinik seciniz:");
			scanf("%s",&poliklinik);
			printf("\n--------------------------------------------------------------------\n");
		// bakiye bilgisi alma ve �deme ekran�
			printf("lutfen bakiyenizi giriniz:");
			scanf("%d",&bakiye);
			printf("muayene ucretiniz %d TL'dir\n onayliyor musunuz? (E/H): ",ucret); scanf("%s", &odeme);
			
			     	if(odeme=='e' || odeme=='E'){
					   	if(bakiye-ucret>=0){
					   		setColor(2);
					   		printf("\n\nISLEM ONAYLANMISTIR\n\n");
					   		setColor(7);
					   		kasa=kasa+ucret;// g�n sonu i�in �denilen �cretin topland��� yer
					   		kalan(bakiye,ucret);
						}
						// tek seferlik tekrar bakiye sorma ekran�
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
			
	// gazi ve �ehit yak�nlar� i�in �cret al�nmaz direkt randevu olu�turulur		
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
	//yanl�� se�enek se�ildi�i zaman uyar� verir
		else{
			setColor(4);
			printf("\n\nGECERSIZ GIRIS YAPTINIZ\n\n");
			setColor(7);
			break;
		}
		
		
	// randevu tarihi belirleme ekran� uygun zaman aral��� se�ildi�i zaman randevuyu yazd�r�r
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
										
	// G�n sonu al�n�r gelen hastalar�n listesi g�n sonu muayene �cretinden gelen gelirlerin toplam� ekrana yazd�r�l�r				
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
			
		// G�m sonu ekran�nda ��k�� yapmak i�in kullan�l�r	
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
		// �deme=h oldu�u zaman sistemi yeniden ba�lat�r ama� hay�r a bas�ld��� zaman ismin listeye kaydedilmemesi
	    if(odeme=='h'|| odeme=='H'){
	 	break;
	 	}
		 if(secenek==2 && yas<65) break;			
	}
}

	// d�ng�den ��kmak i�in kullan�l�r ve sistem kapan�r		
	if(giris==3){
		setColor(2);
		printf("\nBASARIYLA CIKIS YAPTINIZ\n");
		setColor(7);
		break;
		}
	// yanl�� giri�tem dolay� uyar� ekran�	
		if(!(giris==1 || giris==2 || giris==3)){
			setColor(4);
		    printf("\n\nHATALI GIRIS YAPTINIZ!!\n\n");
		    setColor(7);
		}				
	}
	return 0;
}
