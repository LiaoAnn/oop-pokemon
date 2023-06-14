import MyBlastoise from '@/assets/my-blastoise.png';
import MyCharizard from '@/assets/my-charizard.png';
import MyMonster from '@/assets/my-monster.png';
import MyVenusaur from '@/assets/my-venusaur.png';
import OthersBlastoise from '@/assets/others-blastoise.png';
import OthersCharizard from '@/assets/others-charizard.png';
import OthersMonster from '@/assets/others-monster.png';
import OthersMonster2 from '@/assets/others-monster2.png';
import OthersMonster3 from '@/assets/others-monster3.png';
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
    default:
      const r = Math.random() * 3;
      if (side == 'my') return MyMonster;
      else if (r < 1) return OthersMonster;
      else if (r < 2) return OthersMonster2;
      else return OthersMonster3;
  }
};

export default { GetMonsterImage };
