<template>
  <div class="container">
    <TopBar/>
    <section class="top-section">
      <DescriptionUnique
        title='Agroindústria'
        :description="[{'title': 'Como nosso produto pode te ajudar', 'text':'Nosso foco é no desenvolvimento de sistemas de carregamento e distribuição de nutrientes para agricultura. '}, 
                       {'title': 'Diferencial', 'text':'Embora hoje já existam processos e protocolos clássicos, com um pouco mais de valor agregados (principalmente no que diz respeito ao aporte de nutrientes e sua associação com os agentes naturais, que atuem em pragas e microrganismos) é possível obter produtos mais eficientes operacionalmente e financeiramente. '},
                       {'title': 'Produtos', 'text':'Temos a solução para carregamentos específicos solúveis de nutrientes para diversos tipos de culturas, com produtos que vão desde simples nutrientes ate agro protetores de origem natural e sintética. '},
                       {'title': 'abba', 'text':'Estes nano carreadores podem ser adicionados diretamente aos caldos e aplicados de forma eficiente em cana-de açúcar, cítricos, soja vinhedos, de forma a proteger e ajudar no crescimento e produção por hectare. '},
                       {'title': 'abba', 'text':'A versatilidade permite que cada produto seja desenhado dentro da necessidade de cada cliente. '}]"
      />
    </section>
    <footer class = "info">
      <Footer 
        email="btpesquisa.cientifica@gmail.com"	
        tel="(16) 991315332"
      />
    </footer>
  </div>
</template>

<script>
import Footer from '~/components/Footer.vue'
import CardHolder from '~/components/CardHolder.vue'
import TopBar from '~/components/TopBar.vue'
import DescriptionUnique from '~/components/DescriptionUnique.vue'
import PersonCardHolder from '~/components/PersonCardHolder.vue'

export default {
  components: {
    CardHolder,
    Footer,
    TopBar,
    DescriptionUnique,
    PersonCardHolder
  }
}
</script>

<style scoped>

.top-section {
  background-color: white;
  padding-bottom: 30px;
}
.container {
  font-family: 'Roboto Slab' ,'Arial',sans-serif;
  position: absolute;
  bottom: 0;
  top: 0;
  left: 0;
  right: 0;
  max-width: 100%;
  text-align: center;
}

.info {
  position: fixed;
  bottom: 0;
  left: 0;
  right: 0;
  background-color: #0d223b;
  padding-bottom: 10px;
  width: 100%;
  min-width: 100%;
}

</style>