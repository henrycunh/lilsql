<template>
  <div class="container">
    <TopBar/>
    <section class="top-section">
      <Description
        title='O que fazemos.'
        description='A BT Científica é uma startup focada em pesquisa e desenvolvimento de processos e/ou produtos químicos e farmacêuticos baseados em Nanotecnologia.'
      />
      <CardHolder/>
    </section>
    <PersonCardHolder/>
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
import Description from '~/components/Description.vue'
import PersonCardHolder from '~/components/PersonCardHolder.vue'

export default {
  components: {
    CardHolder,
    Footer,
    TopBar,
    Description,
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
  position: absolute;
  bottom: 0;
  top: 0;
  left: 0;
  right: 0;
  max-width: 100%;
  background-color: #0d223b;
  text-align: center;
}

.info {
  position: relative;
  bottom: 0;
  left: 0;
  right: 0;
  background-color: #0d223b;
  height: 100%;
  padding-top: 10px;
  width: 100%;
  min-width: 100%;
  height: 65px;
  clear: both;
}

</style>