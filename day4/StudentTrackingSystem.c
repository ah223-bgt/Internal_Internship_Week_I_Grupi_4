/* ============================================
   Student Progress Tracker — Dita 4
   Internship: Java 1 | Autor: [emri yt]
   ============================================ */

#include <stdio.h>
#include <string.h>

/* -- Konstantet e programit -- */
#define MAX_STUDENTS 5
#define MAX_NAME     50

/* -- enum për statusin e studentit -- */
typedef enum {
    STATUS_AKTIV    = 0,
    STATUS_KALOI    = 1,
    STATUS_RRËZOI   = 2
} StudentStatus;

/* -- Struktura kryesore e të dhënave -- */
typedef struct {
    int           id;
    char          emri[MAX_NAME];
    float         nota;        /* 0.0 - 10.0 */
    StudentStatus status;
} Student;

/* -- Lista globale e studentëve -- */
Student lista[MAX_STUDENTS];
int     numStudentesh = 0;

/* ---- Funksionet ---- */

/* Konverton enum në tekst të lexueshëm (pointer si parametër) */
const char* statusNëTekst(StudentStatus *s) {
    switch (*s) {
        case STATUS_AKTIV:  return "Aktiv";
        case STATUS_KALOI:  return "Kaloi";
        case STATUS_RRËZOI: return "Rrëzoi";
        default:            return "E panjohur";
    }
}

/* Shton një student të ri në listë */
void shtoStudent() {
    if (numStudentesh >= MAX_STUDENTS) {
        printf("Lista është plot! Maximimumi është %d studente.\n", MAX_STUDENTS);
        return;
    }

    Student *s = &lista[numStudentesh]; /* pointer tek regjistri i ri */
    s->id = numStudentesh + 1;

    printf("Emri i studentit: ");
    scanf(" %49[^\n]", s->emri);

    printf("Nota (0.0 - 10.0): ");
    scanf("%f", &s->nota);

    if (s->nota < 0.0f || s->nota > 10.0f) {
        printf("Nota nuk është e vlefshme. Vendosem 0.0.\n");
        s->nota = 0.0f;
    }

    /* Vendos statusin automatikisht bazuar në notë */
    s->status = (s->nota >= 5.0f) ? STATUS_KALOI : STATUS_RRËZOI;

    numStudentesh++;
    printf("Studenti '%s' u shtua me sukses.\n", s->emri);
}

/* Shfaq të gjithë studentët */
void shfaqStudentët() {
    if (numStudentesh == 0) {
        printf("Nuk ka asnjë student të regjistruar ende.\n");
        return;
    }

    printf("\n%-4s %-20s %-6s %-10s\n",
           "ID", "Emri", "Nota", "Statusi");
    printf("----------------------------------------\n");

    for (int i = 0; i < numStudentesh; i++) {
        printf("%-4d %-20s %-6.1f %-10s\n",
               lista[i].id,
               lista[i].emri,
               lista[i].nota,
               statusNëTekst(&lista[i].status)); /* &= pointer */
    }
    printf("\n");
}

/* Shfaq menunë kryesore */
void shfaqMenunë() {
    printf("\n=== Student Progress Tracker ===\n");
    printf("1. Shto student\n");
    printf("2. Shfaq të gjithë studentët\n");
    printf("0. Dil\n");
    printf("Zgjidhni: ");
}

/* Funksioni kryesor */
int main() {
    int zgjedhja;
    int duke_punuar = 1;

    while (duke_punuar) {
        shfaqMenunë();
        scanf("%d", &zgjedhja);

        switch (zgjedhja) {
            case 1: shtoStudent();      break;
            case 2: shfaqStudentët();   break;
            case 0:
                printf("Mirupafshim!\n");
                duke_punuar = 0;
                break;
            default:
                printf("Opsion i pavlefshëm. Provo sërish.\n");
        }
    }

    return 0;
}
