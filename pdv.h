#ifndef PDV_H_INCLUDED
#define PDV_H_INCLUDED

void TelaPDV();

void ListaDeProdutos();

void MontarCarrinho();

void AdicionarItemCarrinho(Carrinho **carrinho);

void RemoverItemCarrinho(Carrinho **carrinho);

void FinalizarCarrinho(Carrinho **carrinho);

void MostrarCarrinho(Carrinho **carrinho);

void TelaVendaAtual(Carrinho **carrinho);

void AplicarDesconto(Carrinho **carrinho);

void SalvarCarrinho(Carrinho **carrinho);

void CancelarCarrinho(Carrinho **carrinho);

void TelaCarrinhos();

void ListarCarrinhosGuardados();

#endif // PDV_H_INCLUDED
