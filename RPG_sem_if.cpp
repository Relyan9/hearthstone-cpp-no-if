#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. ESTADO INICIAL (Conforme requisitos do PDF da Profª Cristina)
    string nome;
    int vida = 30;    
    int mana = 20;    
    int ataque = 10; 
    int escolha;

    // EXPLICAÇÃO DO JOGO
    cout << "============================================================" << endl;
    cout << "           BEM-VINDO AO HEARTHSTONE: UNIVALI SAGA           " << endl;
    cout << "============================================================" << endl;
    cout << "COMO JOGAR:" << endl;
    cout << "1. Voce e um Mago-Guerreiro em jornada ate a universidade." << endl;
    cout << "2. Cada escolha e uma CARTA que concede BUFFS e DEBUFFS." << endl;
    cout << "3. O combate e MATEMATICO: se seu ATK >= HP do monstro," << endl;
    cout << "   voce o derrota sem sofrer dano. Caso contrario, voce apanha!" << endl;
    cout << "4. Nao ha 'if' ou 'while'. Suas decisoes sao definitivas." << endl;
    cout << "============================================================" << endl;
    
    cout << "Digite o nome do seu Heroi: "; 
    cin >> nome;

    // --- INIMIGO 1: O VIGIA DOS PORTÕES DIMENSIONAIS ---
    int gobVida = 15;
    int gobAtk = 6;
    cout << "\n[CENARIO 1: A SAIDA DO VAZIO]" << endl;
    cout << "Ao abrir a porta de casa, o mundo real sumiu. Um GOBLIN fétido," << endl;
    cout << "armado com uma adaga de osso, guarda o portal da sua garagem!" << endl;
    cout << "INFO : Inimigo (HP:15 | ATK:6) | STATUS DO JOGADOR: Vida[" << vida << "] Mana[" << mana << "] Atk[" << ataque << "]" << endl;
    cout << "1 - Furia de Sangue (+10 Atk | -6 Vida)" << endl;
    cout << "2 - Concentracao (+2 Atk | +4 Mana)" << endl;
    cout << "Sua carta: "; cin >> escolha;

    int m1 = (2 - escolha); int m2 = (escolha - 1); // Esta linha transforma a entrada do usuário (1 ou 2) em uma chave liga/desliga (0 ou 1).
    ataque = ataque + (m1 * 10) + (m2 * 2); // O programa aplica os resultados de ambas as escolhas ao mesmo tempo. // Se o jogador escolheu 1, a conta vira ataque + (1 * 10) + (0 * 2). O bônus da segunda opção é anulado pela multiplicação por zero.
    vida = vida - (m1 * 6); // Vida: Se m1 for 1, o herói perde 6 de vida. Se for 0, a perda é 0 * 6 = 0
    mana = mana + (m2 * 4); // Mana: Se m2 for 1, o herói ganha 4 de mana. Se for 0, o ganho é nulo.

    int gobVivo = (gobVida > ataque); // Se a vida do Goblin ($15$) for maior que o seu ataque, o C++ atribui o valor 1 (Verdadeiro) para a variável gobVivo.
    vida = vida - (gobVivo * gobAtk); // Se o seu ataque for igual ou maior que a vida do Goblin, a variável recebe 0 (Falso).
    cout << (gobVivo * 1 ? ">> O Goblin resistiu e cortou seu braço!" : ">> Voce explodiu o Goblin com um golpe so!") << endl;

    // --- INIMIGO 2: O LEVIATÃ DAS ÁGUAS TURVAS ---
    int murVida = 25;
    int murAtk = 8;
    cout << "\n[CENARIO 2: A PONTE SOBRE O ABISMO]" << endl;
    cout << "O Rio Itajai-Acu transbordou energia caotica. Um MURLOC GIGANTE," << endl;
    cout << "com escamas de ferro, salta das profundezas para devorar sua moto!" << endl;
    cout << "INFO: Inimigo(HP:25 | ATK:8) | STATUS: Vida[" << vida << "] Mana[" << mana << "] Atk[" << ataque << "]" << endl;
    cout << "1 - Golpe Elemental (+15 Atk | -10 Mana)" << endl;
    cout << "2 - Postura Defensiva (+0 Atk | +10 Vida | -5 Mana)" << endl;
    cout << "Sua carta: "; cin >> escolha;

    m1 = (2 - escolha); m2 = (escolha - 1);
    ataque = ataque + (m1 * 15);
    vida = vida + (m2 * 10);
    mana = mana - (m1 * 10) - (m2 * 5);

    int murVivo = (murVida > ataque);
    vida = vida - (murVivo * murAtk);
    cout << (murVivo * 1 ? ">> O Leviata te atingiu com a cauda!" : ">> O monstro marinho virou poeira cosmica!") << endl;

    // --- INIMIGO 3: O TITÃ DE PEDRA DO PEDÁGIO ---
    int ogroVida = 45;
    int ogroAtk = 12;
    cout << "\n[CENARIO 3: A MONTANHA DA RUA HEITOR LIBERATO]" << endl;
    cout << "A estrada virou um desfiladeiro. Um OGRO DE PEDRA barra a passagem," << endl;
    cout << "batendo um tronco de arvore no chao e exigindo sua alma como pedagio!" << endl;
    cout << "INFO: Inimigo(HP:45 | ATK:12) | STATUS: Vida[" << vida << "] Mana[" << mana << "] Atk[" << ataque << "]" << endl;
    cout << "1 - Sacrificio Arcano (+20 Atk | -10 Vida)" << endl;
    cout << "2 - Drenar Energia (+5 Atk | +8 Mana | -5 Vida)" << endl;
    cout << "Sua carta: "; cin >> escolha;

    m1 = (2 - escolha); m2 = (escolha - 1);
    ataque = ataque + (m1 * 20) + (m2 * 5);
    vida = vida - (m1 * 10) - (m2 * 5);
    mana = mana + (m2 * 8);

    int ogroVivo = (ogroVida > ataque);
    vida = vida - (ogroVivo * ogroAtk);
    cout << (ogroVivo * 1 ? ">> O impacto do Ogro estremeceu seus ossos!" : ">> O Tita de pedra desmoronou diante de voce!") << endl;

    // --- INIMIGO 4: O DRAGÃO DA UNIVALI (BOSS FINAL) ---
    int bossVida = 80;
    int bossAtk = 20;
    cout << "\n[ULTIMO BOSS: O PORTAL DO CONHECIMENTO]" << endl;
    cout << "As torres da UNIVALI surgem, mas um DRAGAO DE CINZAS E FOGO" << endl;
    cout << "paira sobre o bloco de computacao. Ele ruge um enigma mortal!" << endl;
    cout << "INFO: BOSS(HP:80 | ATK:20) | STATUS FINAL: Vida[" << vida << "] Mana[" << mana << "] Atk[" << ataque << "]" << endl;
    cout << "1 - PIROEXPLOSAO FINAL (Dobra o Atk | Mana vira 0 | -5 Vida)" << endl;
    cout << "2 - Perseveranca do Estudante (+5 Atk | +15 Vida | -10 Mana)" << endl;
    cout << "Sua carta: "; cin >> escolha;

    m1 = (2 - escolha); m2 = (escolha - 1);
    ataque = (m1 * (ataque * 2)) + (m2 * (ataque + 5));
    mana = (m1 * 0) + (m2 * (mana - 10));
    vida = vida - (m1 * 5) + (m2 * 15);

    int bossVivo = (bossVida > ataque); 
    vida = vida - (bossVivo * bossAtk); 

    // --- FINAL DO JOGO (Veredito Matemático) ---
    int vitoria = (vida > 0) * (bossVivo == 0); // A Lógica: Aqui você está simulando um operador lógico E (AND) usando multiplicação.

    cout << "\n============================================================" << endl;
    cout << "RESUMO DA JORNADA DE " << nome << ":" << endl;
    cout << "VIDA FINAL: " << vida << " | MANA FINAL: " << mana << " | ATAQUE FINAL: " << ataque << endl;
    cout << "------------------------------------------------------------" << endl;
    string msg[2] = {
    "DERROTA! Sua jornada termina aqui. O Dragao incinerou seu diploma...",
    "VITORIA! O Dragao caiu. Voce entrou na sala e tirou 10 em Algoritmos!"
};

cout << msg[vitoria] << endl;

    /* OBSERVACOES INDISPENSAVEIS (Obs1):
       - IA UTILIZADA: O Gemini foi consultado para converter mecanicas de RPG em formulas matematicas
         que substituem estruturas de decisao (if/else) e lacos de repeticao, garantindo 100% de
         aderencia as restricoes do T1 da Profª Cristina.
       - LOGICA: O sistema usa multiplicadores binarios (0 e 1) baseados na entrada do usuario para 
         ativar ou anular os efeitos das escolhas de forma puramente sequencial.
    */

    return 0;
}