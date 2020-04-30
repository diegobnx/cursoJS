const carrinho = [
    '{ "nome" : "Borracha", "preco" : "R$3.45"}',
    '{ "nome" : "Caderno", "preco" : "R$13.90"}',
    '{ "nome" : "Kit de Lapis", "preco" : "R$41.22"}',
    '{ "nome" : "Caneta", "preco" : "R$7.50"}'
]

const resultado = carrinho.map(json => JSON.parse(json)).map(produto => produto.preco);

console.log(resultado);