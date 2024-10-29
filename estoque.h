#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

void TelaEstoque();

void ListarEstoque(Produto produto);

void MostrarEstoque();

void BuscarEstoque();

void AdicionarQuantidade(Produto *produto, float quantidade);

void SubtrairQuantidade(Produto *produto, float quantidade);

void EditarEstoque(Produto produto);

#endif // ESTOQUE_H_INCLUDED
