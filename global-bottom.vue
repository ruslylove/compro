<!-- global-bottom.vue -->
<script setup>
import { useNav, useSlideContext } from '@slidev/client'

const { currentSlideNo, total } = useNav()
const { $slidev } = useSlideContext()
</script>

<template>
    <footer class="absolute bottom-0 right-0 p-2 opacity-40">010153002 Computer Programming {{ $slidev.configs.semester }} - Page {{ currentSlideNo }} / {{ total }}</footer>
</template>
