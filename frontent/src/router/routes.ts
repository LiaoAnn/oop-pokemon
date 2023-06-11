import type { RouteRecordRaw } from 'vue-router';

const routes: RouteRecordRaw[] = [
  {
    path: '/',
    component: () => import('@/layouts/MainLayout.vue'),
    children: [
      {
        path: '',
        name: 'Home',
        component: () => import('@/pages/HomePage.vue')
      },
      {
        path: 'game',
        name: 'Game',
        component: () => import('@/pages/GamePage.vue')
      }
    ]
  },
  {
    path: '/:catchAll(.*)*',
    name: 'NotFound',
    component: () => import('@/pages/NotFoundPage.vue')
  }
];

export default routes;
