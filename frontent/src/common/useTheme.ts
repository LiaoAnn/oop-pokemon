import { type GlobalThemeOverrides } from 'naive-ui';
import { computed, ref } from 'vue';

export default function useTheme() {
  const primaryColor = '#3d7dca';
  const darkPrimaryColor = '#003a70';
  const secondaryColor = '#ffcb05';
  type Theme = null | 'dark';
  const theme = ref<Theme>(null);

  const baseThemeOverrides: GlobalThemeOverrides = {
    common: {
      primaryColor: primaryColor,
      primaryColorHover: primaryColor,
      primaryColorPressed: primaryColor,
      primaryColorSuppl: primaryColor,
      fontWeightStrong: '600'
    },
    Menu: {
      itemTextColorHorizontal: secondaryColor,
      itemTextColorHorizontalHover: secondaryColor,
      itemTextColorHorizontalPressed: secondaryColor,
      itemTextColorHorizontalActive: secondaryColor,
      itemTextColorHorizontalActiveHover: secondaryColor,
      itemTextColorHorizontalActivePressed: secondaryColor,
      itemTextColorActiveHorizontal: secondaryColor,
      itemTextColorActiveHorizontalHover: secondaryColor,
      itemTextColorActiveHorizontalPressed: secondaryColor,
      itemTextColorActiveHoverHorizontal: secondaryColor,
      itemTextColorActiveHoverHorizontalHover: secondaryColor,
      itemTextColorActiveHoverHorizontalPressed: secondaryColor,
      itemTextColorActivePressedHorizontal: secondaryColor,
      itemTextColorActivePressedHorizontalHover: secondaryColor
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
    darkPrimaryColor,
    secondaryColor,
    theme,
    themeOverrides,
    toggleTheme
  };
}
