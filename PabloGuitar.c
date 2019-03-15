#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
#include <math.h>
#include <time.h>

GLfloat fAspect;
GLfloat angulo;
int aux=6600,ty=6600;
int y,i,circle_points = 30,cont=1;
float angle,tempo=0;
time_t inicio,fim;
// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0,ty,0);

	// com a cor corrente
	glColor3f(0.59f, 0.29f, 0.0f);  
	
	// Desenha a porta e a janela  
	glBegin(GL_QUADS);
		glVertex2f(-40.0f,-6500.0f);
		glVertex2f(-40.0f, 6500.0f);
		glVertex2f( 40.0f, 6500.0f);
		glVertex2f( 40.0f,-6500.0f);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.4f, 0.4f, 0.4f); 
		glVertex2f(-24.0f,-6500.0f);
		glVertex2f(-24.0f, 6500.0f);
		glVertex2f(-8.0f, -6500.0f);
		glVertex2f(-8.0f,6500.0f);
		glVertex2f(8.0f,-6500.0f);
		glVertex2f(8.0f, 6500.0f);
		glVertex2f(24.0f,-6500.0f);
		glVertex2f(24.0f, 6500.0f);
	glEnd();
	glBegin(GL_LINES);
		glLineWidth(6);
		glColor3f(1.0f, 1.0f, 1.0f); 
		glVertex2f(-40.0f,-6500.0f);
		glVertex2f(-40.0f, 6500.0f);
		glVertex2f( 40.0f, 6500.0f);
		glVertex2f( 40.0f,-6500.0f);
		for(y=-6500;y!=6500;y=y+100) {
			glVertex2f(-40.0f,y);
			glVertex2f(40.0f,y);	
		}
	glEnd();
	glPopMatrix();
	glBegin(GL_POLYGON);
		glColor3f(0.0f, 1.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(-32+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(-32+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(-16+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(-16+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(0+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(0+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(16+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(16+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.65f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(32+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(32+(cos(angle)*7.5), -210.0+(sin(angle)*7.5));
		}
	glEnd();
	glPopMatrix();
	if(cont==1) {
		tempo=tempo+0.01;
		printf("tempo acrescimo %.2f\n",tempo);
	}
	if(cont==1&&aux<=6290) {
		inicio=time(NULL);
		printf("Inicio: %.20f\n",inicio);
		cont++;
	}
	if(cont==2) {
		tempo=tempo+0.01;
		printf("tempo %.2f ty %d\n",tempo,ty);
	}
	if(cont==2&&aux<=-6700) {
		fim=time(NULL);
		printf("Fim: %.20f\n",fim);
		printf("Total: %.20f\n", difftime(fim,inicio));
		cont++;
	}
	//printf("%.2f\n",tempo);
	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(45,fAspect,0.5,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(0,-330,80, 0,0,0, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada pela GLUT a cada intervalo de tempo
void Anima(int value)
{
	ty=ty-3;
	aux=ty;
	// Redesenha o "teapot" em outra posição
	glutPostRedisplay();
	glutTimerFunc(1,Anima, 1);
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{   
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
}

// Programa Principal 
int main(void)
{
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 

	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(5,5); 

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450); 

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Pablo Guitar");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);

	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a função callback que será chamada a cada intervalo de tempo
	glutTimerFunc(1, Anima, 1);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a função responsável por fazer as inicializações 
	Inicializa();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
