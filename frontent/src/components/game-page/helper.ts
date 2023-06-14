import MyBlastoise from '@/assets/my-blastoise.png';
import MyCharizard from '@/assets/my-charizard.png';
import MyVenusaur from '@/assets/my-venusaur.png';
import OthersBlastoise from '@/assets/others-blastoise.png';
import OthersCharizard from '@/assets/others-charizard.png';
import OthersVenusaur from '@/assets/others-venusaur.png';
import type { Monster } from '@/common/useWebSocket';

const GetMonsterImage = (monster: Monster, side: 'my' | 'others') => {
  switch (monster.name) {
    case 'Blastoise':
      return side == 'my' ? MyBlastoise : OthersBlastoise;
    case 'Charizard':
      return side == 'my' ? MyCharizard : OthersCharizard;
    case 'Venusaur':
      return side == 'my' ? MyVenusaur : OthersVenusaur;
  }
};

export default { GetMonsterImage };
