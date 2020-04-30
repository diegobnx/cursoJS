const produtos = [
    { nome: 'Notebook', preco: 2499, fragil: true},
    { nome: 'iPad Pro', preco: 4199, fragil: true},
    { nome: 'Copo de Vidro', preco: 12.49, fragil: true},
    { nome: 'Copo de Plastico', preco: 18.99, fragil: false}
]


produtoCaro = produtos => produtos.preco > 500;
produtoBarato = produtos => produtos.preco < 100;
produtoFragil = produtos => produtos.fragil;

console.log(produtos.filter(produtoBarato))

// produtoCaro = produtos.filter(function(p){
//     if (p.preco > 2000) {
//         return console.log(`Produtos caros: ${p.nome} = R$${p.preco}`)
//     }
//     else{
//         return console.log(`Produtos baratos: ${p.nome} = R$${p.preco}`)
//     }
// })