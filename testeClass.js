class Pessoa{
    constructor(nome){
        this.nome = nome;
    }

    falar() {
        console.log(`Meu nome é ${this.nome}`);
    }
}

const pe1 = new Pessoa();
pe1.nome = 'Diego'
pe1.falar();