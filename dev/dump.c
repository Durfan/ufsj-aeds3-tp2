/*
void polygon(int num_teams) {
    int i,j, turno;
    int n2 = num_teams/2;
    int S0[num_teams+1][num_teams-1];
    int clubs[num_teams+1];
    int club1, club2;

    for (i=0; i<num_teams; i++) clubs[i]=i+1;
    for (turno=0; turno<num_teams-1; turno++) {
        for (i=0; i<n2; i++) {
            club1 = clubs[n2-i];
            club2 = clubs[n2+i+1];
            S0[n2-i][turno] = club2;
            S0[n2+i+1][turno] = club1;
        }
        rotate(clubs,num_teams);
    }

    for (i=1; i<=num_teams; i++) {
        for (j=0; j<num_teams-1; j++) {
            printf("%d ", S0[i][j]);
        }
        printf("\n");
    }
}
*/