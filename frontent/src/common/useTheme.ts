import { type GlobalThemeOverrides } from 'naive-ui';
import { computed, ref } from 'vue';

export default function useTheme() {
  const primaryColor = '#ffcb05';
  const secondaryColor = '#3d7dca';
  const darkSecondaryColor = '#003a70';
  type Theme = null | 'dark';
  const theme = ref<Theme>(null);

  const baseThemeOverrides: GlobalThemeOverrides = {
    common: {
      primaryColor: secondaryColor,
      primaryColorHover: secondaryColor,
      primaryColorPressed: secondaryColor,
      primaryColorSuppl: secondaryColor,
      fontWeightStrong: '600'
    },
    Menu: {
      itemTextColorHorizontal: 'white',
      itemTextColorActiveHorizontal: primaryColor,
      itemTextColorActiveHoverHorizontal: primaryColor,
      itemTextColorHoverHorizontal: primaryColor
    }
  };

  const lightThemeOverrides: GlobalThemeOverrides = {
    ...baseThemeOverrides,
    common: {
      ...baseThemeOverrides.common
    }
  };

  const darkThemeOverrides: GlobalThemeOverrides = {
    ...baseThemeOverrides,
    common: {
      ...baseThemeOverrides.common
    }
  };

  const themeOverrides = computed(() => {
    return theme.value === 'dark' ? darkThemeOverrides : lightThemeOverrides;
  });

  const toggleTheme = () => {
    theme.value = theme.value === 'dark' ? null : 'dark';
  };

  return {
    primaryColor,
    darkSecondaryColor,
    secondaryColor,
    theme,
    themeOverrides,
    toggleTheme
  };
}
