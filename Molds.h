void Moldura(void){
	system("cls");
	
	int i;
	for(i=0; i<115; i++)
	{
		gotoxy(i,1); printf("%c",205);        //Linha Horizontal Superior
		gotoxy(i-1,3); printf("%c",205);      //Linha Horizontal central
		gotoxy(i-1,28); printf("%c",205);     //Linha Horizontal central
		gotoxy(i-1,2); printf("%c",176);      //Linha Horizontal Efeito
		gotoxy(i-1,29); printf("%c",176);     //Linha Horizontal Efeito
		gotoxy(i,30); printf("%c",205);		  //Linha Horizontal Inferior
		gotoxy(1,i-85); printf("%c",186);	  //Linha Vertical Esquerda
		gotoxy(114,i-85); printf("%c",186);   //Linha Vertical Direita
	}
	gotoxy(114,3); printf("%c", 185);	  //Canto Centro Esquerdo
	gotoxy(114,28); printf("%c", 185);	  //Canto Centro Esquerdo
	gotoxy(1,3); printf("%c", 204);		  //Canto Centro Esquerdo
	gotoxy(1,28); printf("%c", 204);	  //Canto Centro Esquerdo
	gotoxy(1,1); printf("%c", 201);		  //Canto Superior Esquerdo
	gotoxy(114,1); printf("%c", 187);	  //Canto Superior Direito
	gotoxy(1,30); printf("%c", 200);	  //Canto Inferior Esquerdo
	gotoxy(114,30); printf("%c", 188);	  //Canto Inferior Direito
	gotoxy(50,10);
}

void MoldInsere(void){
	system("cls");
	
	Moldura();
	int i;
	for(i=15; i<57; i++)
	{
		gotoxy(i,8); printf("%c",196);   //Linha Inferior
		gotoxy(i,10); printf("%c",196);  //Linha Superior
		gotoxy(14,10); printf("%c",192); //Canto inferior esquerdo
		gotoxy(14,8); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,9); printf("%c",179);	 //Canto centro esquerdo
		gotoxy(57,9); printf("%c",179);	 //Canto centro direito
		gotoxy(57,8); printf("%c",191);  //Canto superior direito
		gotoxy(57,10); printf("%c",217); //Canto inferior direito
	}
	gotoxy(45,2); textcolor(2); printf(" INSERINDO NOVO USUARIO ");
	gotoxy(16,9); printf("Insira o Codigo de Usuario: ");
	gotoxy(44,9); textcolor(7); printf("xxx-xx-xxxx");
	
	for(i=59; i<100; i++)
	{
		gotoxy(i,8); printf("%c",196);   //Linha Inferior
		gotoxy(i,10); printf("%c",196);  //Linha Superior
		gotoxy(59,10); printf("%c",192); //Canto inferior esquerdo
		gotoxy(59,8); printf("%c",218);  //Canto superior esquerdo
		gotoxy(59,9); printf("%c",179);	 //Canto centro esquerdo
		gotoxy(100,9); printf("%c",179);	 //Canto centro direito
		gotoxy(100,8); printf("%c",191);  //Canto superior direito
		gotoxy(100,10); printf("%c",217); //Canto inferior direito
	}
	gotoxy(61,9); textcolor(2); printf("Digite o sexo [F / M]: "); textcolor(7);
	
	for(i=15; i<100; i++)
	{
		gotoxy(i,11); printf("%c",196);  //Linha Inferior
		gotoxy(i,13); printf("%c",196);  //Linha Superior
		gotoxy(14,13); printf("%c",192); //Canto inferior esquerdo
		gotoxy(14,11); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,12); printf("%c",179);	 //Canto centro esquerdo
		gotoxy(100,12); printf("%c",179);	 //Canto centro direito
		gotoxy(100,11); printf("%c",191);  //Canto superior direito
		gotoxy(100,13); printf("%c",217); //Canto inferior direito
	}
	gotoxy(16,12); textcolor(2); printf("Nome do medicamento:"); textcolor(7);
	
	for(i=15; i<50; i++)
	{
		gotoxy(i,14); printf("%c",196);   //Linha Inferior
		gotoxy(i,16); printf("%c",196);   //Linha Superior
		gotoxy(14,16); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(14,14); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,15); printf("%c",179);  //Canto centro esquerdo
		gotoxy(50,15); printf("%c",179); //Canto centro direito
		gotoxy(50,14); printf("%c",191); //Canto superior direito
		gotoxy(50,16); printf("%c",217); //Canto inferior direito
	}
	gotoxy(16,15); textcolor(2); printf("Data da ultima compra: "); 
	gotoxy(39,15); textcolor(7); printf("xx/xx/xxxx");
	
	for(i=52; i<100; i++)
	{
		gotoxy(i,14); printf("%c",196);   //Linha Inferior
		gotoxy(i,16); printf("%c",196);   //Linha Superior
		gotoxy(52,16); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(52,14); printf("%c",218);  //Canto superior esquerdo
		gotoxy(52,15); printf("%c",179);  //Canto centro esquerdo
		gotoxy(100,15); printf("%c",179); //Canto centro direito
		gotoxy(100,14); printf("%c",191); //Canto superior direito
		gotoxy(100,16); printf("%c",217); //Canto inferior direito
	}
	gotoxy(54,15); textcolor(2); printf("Nome do Pais:"); textcolor(7);
}

void MoldExclui(void){
	system("cls");
	
	Moldura(); gotoxy(47,2);textcolor(2); printf(" *** EXCLUIR PAIS *** "); textcolor(7);
	int i;
	for(i=25; i<85; i++)
	{
		gotoxy(i,14); printf("%c",196);   //Linha Inferior
		gotoxy(i,16); printf("%c",196);   //Linha Superior
		gotoxy(25,16); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(25,14); printf("%c",218);  //Canto superior esquerdo
		gotoxy(25,15); printf("%c",179);  //Canto centro esquerdo
		gotoxy(85,15); printf("%c",179); //Canto centro direito
		gotoxy(85,14); printf("%c",191); //Canto superior direito
		gotoxy(85,16); printf("%c",217); //Canto inferior direito
	}
	gotoxy(26,15); textcolor(2); printf("Nome do Pais a ser excluido: "); textcolor(7);
	
}

void MoldExcluiM(void){
	system("cls");
	
	Moldura(); gotoxy(44,2);textcolor(2); printf(" *** EXCLUIR MEDICAMENTO *** "); textcolor(7);
	int i;
	for(i=15; i<100; i++)
	{
		gotoxy(i,11); printf("%c",196);   //Linha Inferior
		gotoxy(i,13); printf("%c",196);   //Linha Superior
		gotoxy(14,13); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(14,11); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,12); printf("%c",179);  //Canto centro esquerdo
		gotoxy(100,12); printf("%c",179); //Canto centro direito
		gotoxy(100,11); printf("%c",191); //Canto superior direito
		gotoxy(100,13); printf("%c",217); //Canto inferior direito
	}
	gotoxy(16,12); textcolor(2); printf("Nome do Medicamento a ser excluido: "); textcolor(7);
}

void MoldExibeM(void){ 
	system("cls");

	Moldura(); gotoxy(44,2); textcolor(2); printf(" *** EXIBIR MEDICAMENTOS DE UM PAIS *** "); textcolor(7);
	int i;
	for(i=15; i<100; i++)
	{
		gotoxy(i,5); printf("%c",196);   //Linha Inferior
		gotoxy(i,7); printf("%c",196);   //Linha Superior
		gotoxy(14,7); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(14,5); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,6); printf("%c",179);  //Canto centro esquerdo
		gotoxy(100,6); printf("%c",179); //Canto centro direito
		gotoxy(100,5); printf("%c",191); //Canto superior direito
		gotoxy(100,7); printf("%c",217); //Canto inferior direito
	}
	gotoxy(16,6); textcolor(2); printf("Pais que sera listado os Medicamentos: "); textcolor(7);	
}

void MoldExibe(void){
	system("cls");

	Moldura(); gotoxy(44,2);textcolor(2); printf(" *** EXIBIR USUARIOS DE UM MEDICAMENTO *** "); textcolor(7);
	int i;
	for(i=15; i<100; i++)
	{
		gotoxy(i,5); printf("%c",196);   //Linha Inferior
		gotoxy(i,7); printf("%c",196);   //Linha Superior
		gotoxy(14,7); printf("%c",192);  //Canto inferior esquerdo
		gotoxy(14,5); printf("%c",218);  //Canto superior esquerdo
		gotoxy(14,6); printf("%c",179);  //Canto centro esquerdo
		gotoxy(100,6); printf("%c",179); //Canto centro direito
		gotoxy(100,5); printf("%c",191); //Canto superior direito
		gotoxy(100,7); printf("%c",217); //Canto inferior direito
	}
	gotoxy(16,6); textcolor(2); printf("Medicamento que sera listado os usuarios: "); textcolor(7);
}
