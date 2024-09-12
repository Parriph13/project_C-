
 #include <stdio.h> // Inclusão da biblioteca "stdio.h" que fornece definição de entrada e saída.
#include <GL/glut.h> // Biblioteca que facilita a criação de programas OpenGL.

// Declaração das variáveis para definir posição e cor do objeto.
float r = 1.0f, g = 0.0f, b = 1.0f; // Corrigido o valor de 'b' para estar no intervalo [0.0, 1.0]
// Variáveis que vão armazenar a posição do objeto na tela.
float positionX = 0.0f;
float positionY = 0.0f;

// Definição do desenho do objeto que no caso vai ser um quadrado.
void objt1() {
    glColor3f(r, g, b); // Definição da cor atual do quadrado.
    glBegin(GL_QUADS); /* Essa função define o tipo de objeto, o parâmetro 
    utilizado é o "GL_QUADS" para formação do quadrilátero */
    
    // Função glVertex2f que permite que o quadrado seja desenhado em diferentes posições na tela.
    glVertex2f(-0.1f + positionX, -0.1f + positionY);
    glVertex2f( 0.1f + positionX, -0.1f + positionY);
    glVertex2f( 0.1f + positionX,  0.1f + positionY);
    glVertex2f(-0.1f + positionX,  0.1f + positionY);
    
    glEnd(); // Termina a definição dos vértices.
}

// Definição da função callback para formação e exibição na tela.
void display() {
    glClear(GL_COLOR_BUFFER_BIT); /* Limpa o buffer de cor, preparando a tela para uma nova renderização, 
    garantindo que qualquer conteúdo anterior seja removido, evitando sobreposição de desenhos antigos. */
    
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de limpeza do buffer de cor.
    
    objt1(); // Chama a função que desenha o quadrado na tela.
    
    glFlush(); /* Essa função garante que todos os comandos sejam executados o mais rápido possível. 
    Força a execução dos comandos de desenho, garantindo que o quadrado seja realmente desenhado na tela. */
}

// Definição da cor de fundo da tela.
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Cor de fundo branco.
}

//Definição de captura do mouse.
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

// Definição para capturar teclas especiais em callback.
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
            printf("Tecla inválida!");
            break;
    }
    
    glutPostRedisplay(); // Atualiza a tela a cada movimento.
}

//Função principal do programa, onde a execução começa.
int main(int argc, char** argv) {
    glutInit(&argc, argv);/*Essa função deve ser chamada antes de qualquer outra função, processa os argumentos 
	da linha de comando para configurar a biblioteca.*/
	
    glutCreateWindow("Meu Primeiro Programa de OpenGL");//Cria uma janela com o título desejado.
	
    glutDisplayFunc(display);/*Registrador da função de callback, será chamada toda vez de que janela precisar ser 
	redesenhada*/
	
    glutMouseFunc(mouse);//Registrador da função de callback, para eventos de mouse.
	
	glutSpecialFunc(capturarSpecialKeypress);//Registrador da função de callback, para eventos de captura de teclas especiais.
	
    init();//Chamada da função de cor do fundo da tela.
	
    glutMainLoop();/*Este loop processa eventos e chama as funções de callback registradas, o programa continuará execuntando até 
	que a janela seja fechada.*/
	
    return 0;//Indica que o programa terminou com sucesso.
}

 
 



