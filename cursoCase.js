function media(nota) {
    if (nota >= 7) {
        console.log('Aprovado!! ' + nota);
    }
    else {
        console.log('Reprovado... ' + nota);
    }
    console.log("Final");
}

const imprimirNota = function (nota){
    switch (Math.floor(nota)){
        case 10: case 9:
            console.log("Quadro de Honra!");
            break;
        case 8: case 7:
            console.log("Aprovado!");
            break;
        case 6: case 5: case 4:
            console.log("Recuperação!");
            break
        case 3: case 2: case 1: case 0:
            console.log("Reprovado!");
            break;
        default:
            console.log("Nota invalida!!");
    }
}

imprimirNota();
//media(10);