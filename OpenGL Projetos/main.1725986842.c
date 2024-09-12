
 #include <stdio.h> // Inclus�o da biblioteca "stdio.h" que fornece defini��o de entrada e sa�da.
#include <GL/glut.h> // Biblioteca que facilita a cria��o de programas OpenGL.

// Declara��o das vari�veis para definir posi��o e cor do objeto.
float r = 1.0f, g = 0.0f, b = 1.0f; // Corrigido o valor de 'b' para estar no intervalo [0.0, 1.0]
// Vari�veis que v�o armazenar a posi��o do objeto na tela.
float positionX = 0.0f;
float positionY = 0.0f;

// Defini��o do desenho do objeto que no caso vai ser um quadrado.
void objt1() {
    glColor3f(r, g, b); // Defini��o da cor atual do quadrado.
    glBegin(GL_QUADS); /* Essa fun��o define o tipo de objeto, o par�metro 
    utilizado � o "GL_QUADS" para forma��o do quadril�tero */
    
    // Fun��o glVertex2f que permite que o quadrado seja desenhado em diferentes posi��es na tela.
    glVertex2f(-0.1f + positionX, -0.1f + positionY);
    glVertex2f( 0.1f + positionX, -0.1f + positionY);
    glVertex2f( 0.1f + positionX,  0.1f + positionY);
    glVertex2f(-0.1f + positionX,  0.1f + positionY);
    
    glEnd(); // Termina a defini��o dos v�rtices.
}

// Defini��o da fun��o callback para forma��o e exibi��o na tela.
void display() {
    glClear(GL_COLOR_BUFFER_BIT); /* Limpa o buffer de cor, preparando a tela para uma nova renderiza��o, 
    garantindo que qualquer conte�do anterior seja removido, evitando sobreposi��o de desenhos antigos. */
    
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de limpeza do buffer de cor.
    
    objt1(); // Chama a fun��o que desenha o quadrado na tela.
    
    glFlush(); /* Essa fun��o garante que todos os comandos sejam executados o mais r�pido poss�vel. 
    For�a a execu��o dos comandos de desenho, garantindo que o quadrado seja realmente desenhado na tela. */
}

// Defini��o da cor de fundo da tela.
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Cor de fundo branco.
}

//Defini��o de captura do mouse.
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                r = 0.0f; g = 0.0f; b = 1.1f; // Define a cor para azul.
                break;
            case GLUT_RIGHT_BUTTON:
                r = 1.0f; g = 0.0f; b = 1.0f; // Define a cor de origem sendo rosa.
                break;
        }
        glutPostRedisplay(); // Atualiza a tela a cada movimento
    }
}

// Defini��o para capturar teclas especiais em callback.
void capturarSpecialKeypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: // Permite que o quadrado se mova para cima.
            positionY += 0.1f;
            break;
        case GLUT_KEY_DOWN: // Permite que o quadrado se mova para baixo.
            positionY -= 0.1f;
            break;
        case GLUT_KEY_LEFT: // Permite que o quadrado se mova para a esquerda.
            positionX -= 0.1f;
            break;
        case GLUT_KEY_RIGHT: // Permite que o quadrado se mova para a direita.
            positionX += 0.1f;
            break;
        default:
            printf("Tecla inv�lida!");
            break;
    }
    
    glutPostRedisplay(); // Atualiza a tela a cada movimento.
}

//Fun��o principal do programa, onde a execu��o come�a.
int main(int argc, char** argv) {
    glutInit(&argc, argv);/*Essa fun��o deve ser chamada antes de qualquer outra fun��o, processa os argumentos 
	da linha de comando para configurar a biblioteca.*/
	
    glutCreateWindow("Meu Primeiro Programa de OpenGL");//Cria uma janela com o t�tulo desejado.
	
    glutDisplayFunc(display);/*Registrador da fun��o de callback, ser� chamada toda vez de que janela precisar ser 
	redesenhada*/
	
    glutMouseFunc(mouse);//Registrador da fun��o de callback, para eventos de mouse.
	
	glutSpecialFunc(capturarSpecialKeypress);//Registrador da fun��o de callback, para eventos de captura de teclas especiais.
	
    init();//Chamada da fun��o de cor do fundo da tela.
	
    glutMainLoop();/*Este loop processa eventos e chama as fun��es de callback registradas, o programa continuar� execuntando at� 
	que a janela seja fechada.*/
	
    return 0;//Indica que o programa terminou com sucesso.
}

 
 



