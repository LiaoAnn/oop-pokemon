import type { RouteRecordRaw } from 'vue-router';

const routes: RouteRecordRaw[] = [
  {
    path: '/',
    name: 'home',
    component: () => import('@/layouts/MainLayout.vue'),
    children: [
      {
        path: '',
        component: () => import('@/pages/HomePage.vue')
      },
      {
        path: '/about',
        component: () => import('@/pages/AboutPage.vue')
      }
    ]
  }
];

export default routes;
